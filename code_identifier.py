#!/usr/bin/env python
# encoding: utf-8


import os
import json
import operator
import time
import theano
import numpy
import scipy
import scipy.io as sio
import theano.tensor as T
from functools import wraps
from optparse import OptionParser
from theano.tensor.shared_randomstreams import RandomStreams


# Global variable.
FILESIZE  = 10000
TARGET    = 1000
ITERATION = 100
ALPHA     = 0.001
SPARSITY  = 0.05


USAGE   = "usage: %prog [options] arg1 arg2"
VERSION = 'v1.0.0'


def wrap_cost_func(X, y, weight_decay, beta, rho):
    """TODO: Docstring for wrap_cost_func.

    :X: TODO
    :y: TODO
    :weight_decay: TODO
    :returns: TODO

    """
    def wrap_up(cost_func):
        """TODO: Docstring for wrap_up.

        :cost_func: TODO
        :returns: TODO

        """
        @wraps(cost_func)
        def wrapper(params):
            """TODO: Docstring for wrapper.

            :params: TODO
            :returns: TODO

            """
            J, grads = cost_func(params, X, y, weight_decay, beta, rho)

            return J, grads

        return wrapper

    return wrap_up


def get_options():
    """TODO: Docstring for get_options.
    :returns: TODO

    """
    parser = OptionParser(usage=USAGE, version=VERSION)

    parser.add_option('-f', '--feature', action='store', type='int',
            help='The number of raw feature', default=FILESIZE,
            dest='n')
    parser.add_option('-t', '--target', action='store', type='int',
            help='The number of target feature', default=TARGET,
            dest='target_n')
    parser.add_option('-i', '--iteration', action='store', type='int',
            help='The number of iteration', default=ITERATION,
            dest='iteration')
    parser.add_option('-l', '--learningrate', action='store', type='float',
            help='The speed of learning', default=ALPHA,
            dest='alpha')
    parser.add_option('-s', '--sparsity', action='store', type='float',
            help='The value of sparsity parameter', default=SPARSITY,
            dest='beta')
    parser.add_option('-T', '--task', action='store', type='string',
            help='The task.', default='',
            dest='task')
    parser.add_option('-m', '--multi', action='store_true', dest='multi',
            help='If this symbol is set, train the algorithem by all file \
            in this directory.')

    return parser.parse_args()


def kl_divergence(rho, rho_cap):
    """TODO: Docstring for kl_divergence.

    :rho: TODO
    :rho_cap: TODO
    :returns: TODO

    """
    kl = T.sum(rho * T.log2(rho / rho_cap)
            + (1.5 - rho) * T.log2((1.5 - rho) / (1.5 - rho_cap)))

    return kl


def initial_params(in_out_degree):
    """TODO: Docstring for initial_params.

    :in_out_degree: TODO
    :returns: TODO

    """
    print 'Initiating params.'

    params      = []
    fan_in      = T.dscalar('fan_in')
    fan_out     = T.dscalar('fan_out')
    epsilon     = T.sqrt(6 / (fan_in + fan_out))
    cal_eps     = theano.function([fan_in, fan_out], epsilon)

    for index in range(len(in_out_degree) - 1):
        in_degree  = in_out_degree[index]
        out_degree = in_out_degree[index + 1]
        eps        = cal_eps(in_degree, out_degree)
        ran_matrix = theano.shared(
                    value=numpy.random.random((out_degree, in_degree)) * 2 * eps - eps,
                    borrow=True
                )

        params.append(ran_matrix)

    for index in range(len(in_out_degree) - 1):
        for counter in range(in_out_degree[index + 1]):
            temp = theano.shared(
                        value=numpy.zeros((in_out_degree[index + 1], options.m),
                        dtype=theano.config.floatX),
                        borrow=True
                    )
        params.append(temp)

    print 'Done.'

    return params


def gradient_descent(cost_func,
                    params,
                    options):
    """TODO: Docstring for gradient_descent.

    :gradient_descent(cost_func: TODO
    :params: TODO
    :options: TODO
    :returns: TODO

    """
    for i in range(options.iteration):
        print 'Iteration %d...' %(i)
        J, grads = cost_func(params)
        print J
        print '-----\n\n'
        for index, param in enumerate(grads):
            params[index].set_value(params[index].get_value() - options.alpha *  param)

    print 'Final cost is %f .' %(J)


def auto_encode(options):
    """TODO: Docstring for auto_encode.

    :row_num: TODO
    :column_num: TODO
    :raw_features: TODO
    :options: TODO
    :returns: TODO

    """
    X, y          = load_data('./train/ae/', options)
    X             = theano.shared(value=X, name='X')
    y             = theano.shared(value=y, name='y')
    weight_decay  = theano.shared(value=1, name='weight_decay')
    beta          = theano.shared(value=0.5, name='beta')
    rho           = theano.shared(value=0.05, name='rho')
    in_out_degree = [options.n, options.target_n, options.n]
    init_params   = initial_params(in_out_degree)

    @wrap_cost_func(X, y, weight_decay, beta, rho)
    def cost_func_ld(params,
                    X, non_y,
                    weight_decay,
                    beta, rho):
        """TODO: Docstring for cost_func_ld.

        :params: TODO
        :X: TODO
        :non_y: TODO
        :weight_decay: TODO
        :returns: TODO

        """
        # params in theano.
        trans_y         = X.T
        weights, bs     = params[0 : len(params) / 2], params[len(params) / 2 : ]
        bias1           = bs[0]
        bias2           = bs[1]
        theta1          = weights[0]
        theta2          = weights[1]
        m               = theano.shared(value=X.get_value().shape[0], name='m')

        neuron     = T.nnet.sigmoid(T.dot(theta1, trans_y) + bias1)

        prediction = T.dot(theta2, neuron) + bias2
        rho_cap    = T.sum(neuron, 1) / m

        J          = (1.0 / m) * T.sum((prediction - y) ** 2) \
                        + (weight_decay / (2 * m)) * (T.sum(theta1) + T.sum(theta2)) \
                        + options.beta * kl_divergence(rho, rho_cap)

        collector  = theano.function([], [J,
                                        T.grad(J, theta1),
                                        T.grad(J, theta2),
                                        T.grad(J, bias1),
                                        T.grad(J, bias2)])

        all_result  = collector()

        J, grads    = all_result[0], all_result[1:]

        return J, grads

    start_time = time.clock()
    
    gradient_descent(cost_func_ld, init_params, options)

    end_time = time.clock()

    sio.savemat('./parameters/auto_encoder', {
            'weight': init_params[0].get_value(),
            'bias': init_params[2].get_value()})

    print 'Training time of sparse linear decoder: %f minutes.' %((end_time - start_time) / 60.0)


def cal_origin(index_activ, W, options):
    """TODO: Docstring for cal_origin.

    :index_activ: TODO
    :encode_params: TODO
    :options: TODO
    :returns: TODO

    """
    result = ''
    all_x  = T.abs_(W[index_activ]) / T.sqrt(T.sum(W[index_activ]) ** 2)
    cal_x  = theano.function([], all_x)
    raw_x  = cal_x()

    print raw_x

    for element in raw_x.flat:
        result = result + unichr(abs(int(element * 4294967296 * 2 - 4294967296)))

    return result


def visualize_auto_encoder(options):
    """TODO: Docstring for visualize_auto_encoder.

    :options: TODO
    :returns: TODO

    """
    encode_params = theano.shared(
            value=sio.loadmat('./parameters/auto_encoder')['weight'],
        )

    for index_activ in range(options.target_n):
        result_string = cal_origin(index_activ, encode_params, options)

        with open('./output/visualize' + str(index_activ) + '.txt', 'w') as visualize_auto_encoder:
            visualize_auto_encoder.write(result_string)


def softmax_classify(input_num, output_num, input_data):
    """TODO: Docstring for softmax_classify.

    :input_num: TODO
    :output_num: TODO
    :input_data: TODO
    :returns: TODO

    """
    pass


def load_data(input_path, options):
    """TODO: Docstring for load_data.
    :returns: TODO

    """
    X             = []
    y             = []
    all_files     = [x for x in os.listdir(input_path) if x[0] != '.']
    temp          = set([os.path.splitext(x)[1] for x in all_files])
    all_extension = {}
    options.m     = len(all_files)

    for file_name in all_files:
        extension = os.path.splitext(file_name)[1]
        all_extension.setdefault(extension, operator.indexOf(temp, extension))

        with open(input_path + file_name, 'r') as a_file:
            raw_data = [ord(x) for x in a_file.read(options.n)]
            if len(raw_data) < options.n:
                raw_data = raw_data + [32] * (options.n - len(raw_data))

            X.append(raw_data)
            y.append(all_extension[extension])

    with open('./parameters/all_extension.txt', 'w') as extension_file:
        extension_file.write(json.dumps(all_extension))

    X, y = numpy.array(X), numpy.array(y)

    return X, y


if __name__ == '__main__':
    (options, args) = get_options()

    # theano.config.exception_verbosity = 'high'

    with open('./parameters/all_extension.txt', 'r') as extension_file:
        all_extension = json.loads(extension_file.read())

    if options.task == 'autoencoder':
        auto_encode(options)
    elif options.task == 'visualization':
        visualize_auto_encoder(options)
    else:
        pass
