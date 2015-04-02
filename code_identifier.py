#!/usr/bin/env python
# encoding: utf-8


import re
import math
import cmath
import numpy
import theano
import operator
import scipy.io as sio
import theano.tensor as T
from util import *
from time import time
from theano import shared
from os import makedirs, listdir
from os.path import exists, join, splitext, isdir


(options, args) = get_options()
PARAM_FOLDER = './param'


def display_tensor(tensor):
    """TODO: Docstring for display_tensor.

    :tensor: TODO
    :returns: TODO

    """
    a = tensor
    b = theano.function([], a)

    print b()

    return 0.0


def get_rho(X, theta1, b1):
    """TODO: Docstring for get_.

    :arg1: TODO
    :returns: TODO

    """
    return T.sum(T.dot(theta1, X)+b1, axis=0)


def kl_divergence(rho, rho_cap):
    """TODO: Docstring for kl_divergence.

    :rho: TODO
    :rho_cap: TODO
    :returns: TODO

    """
    kl = T.sum(rho * T.log2(rho / rho_cap)
            + (1.5 - rho) * T.log2((1.5 - rho) / (1.5 - rho_cap)))

    return kl


def gradient_descent(cost_func, params, iter_num, alpha):
    """TODO: Docstring for gradient_descent.

    :gradient_descent(cost_func: TODO
    :params: TODO
    :options: TODO
    :returns: TODO

    """
    for i in range(iter_num):
        print 'Iteration %d...' %(i)
        J, grads = cost_func(params)
        print 'Cost: %f' % (J)
        print '-----\n'
        for index, param in enumerate(grads):
            params[index] = (params[index] - alpha * param)

    print 'Final cost is %f .' %(J)

    return params


def initial_params(in_out_degree):
    """TODO: Docstring for initial_params.

    :in_out_degree: TODO
    :returns: TODO

    """
    print 'Initiating params.'

    params = []
    for index in range(len(in_out_degree)-1):
        in_degree = in_out_degree[index]
        out_degree = in_out_degree[index+1]
        eps = math.sqrt(6.0/(in_degree+out_degree))
        ran_matrix = numpy.random.random((in_degree, out_degree))*2*eps-eps
        ran_vec = numpy.zeros(out_degree, dtype=theano.config.floatX)
        params.append(ran_matrix)
        params.append(ran_vec)

    print 'Done.\n-----'

    return params


def assess(a, b, flag=0, threshold=0.5):
    """TODO: Docstring for assess.

    :a: TODO
    :b: TODO
    :returns: TODO

    """
    if flag:
        return numpy.mean(numpy.equal(a>=threshold, b>=threshold))
    else:
        return numpy.mean(numpy.equal(a, b))


def sigmoid(z):
    """TODO: Docstring for sigmoid.

    :z: TODO
    :returns: TODO

    """
    return 1 / (1 + cmath.e**(-z))


def predict(X, params):
    """TODO: Docstring for predict.

    :X: TODO
    :params: TODO
    :returns: TODO

    """
    pred = X
    for index in range(len(params)-3):
        theta1, b1 = params[index], params[index+1]
        theta2, b2 = params[index+2], params[index+3]
        pred = numpy.dot(sigmoid(numpy.dot(pred, theta1) + b1), theta2) + b2

    return pred


@log_time
@embed_params(_iter_num=options.iteration, _alpha=options.alpha,
              _decay=options.decay, _beta=options.beta, _rho=options.rho)
def auto_encode(X, y, input_n, hidden_n, _iter_num,
                _alpha, _decay, _beta, _rho):
    """TODO: Docstring for auto_encode.

    :returns: TODO

    """
    m = X.shape[1]
    in_out_degree = [input_n, hidden_n, input_n]
    init_params   = initial_params(in_out_degree)

    t_X, t_weight_decay, t_m = T.dmatrix(), T.dscalar(), T.dscalar()
    t_theta1, t_b1 = T.dmatrix(), T.dvector()
    t_theta2, t_b2 = T.dmatrix(), T.dvector()
    # t_beta = T.dscalar() # t_rho = T.dscalar()
    neuron = T.nnet.sigmoid(T.dot(t_X, t_theta1) + t_b1) # rho_cap = T.sum(neuron, 1) / t_m
    prediction = T.dot(neuron, t_theta2) + t_b2
    J = (1.0 / (2.0 * m)) * T.sum((prediction - t_X) ** 2) \
            + (t_weight_decay / (2 * t_m)) \
            * (T.sum(t_theta1 ** 2) + T.sum(t_theta2 ** 2))

    if input_n < hidden_n:
        J = J + t_beta * kl_divergence(t_rho, rho_cap)

    formula = theano.function([t_X, t_theta1, t_b1, t_theta2, t_b2, t_m,
                               t_weight_decay,],
                              [J, T.grad(J, t_theta1), T.grad(J, t_b1),
                               T.grad(J, t_theta2), T.grad(J, t_b2),])

    def cost_func_ae(params):
        """TODO: Docstring for cost_func_ae.

        :params: TODO
        :returns: TODO

        """
        tmp = formula(X, params[0], params[1], params[2], params[3], m, _decay)

        J, grads = tmp[0], tmp[1:]

        return J, grads

    start_time = time()

    params = gradient_descent(cost_func_ae, init_params, _iter_num, _alpha)

    print 'Training time of sparse linear decoder: %f minutes.' \
            %((time() - start_time) / 60.0)
    print 'The accuracy of ae: %f %%' % (assess(X, predict(X, params), 1))

    sio.savemat('./param/ae_weight_bias', {
            'weight': params[0], 'bias': params[1],
            })


# Under construction.
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
    encode_params = shared(
            value=sio.loadmat('./parameters/auto_encoder')['weight'],
        )

    for index_activ in range(options.target_n):
        result_string = cal_origin(index_activ, encode_params, options)

        with open('./output/visualize' + str(index_activ) + '.txt', 'w') as visualize_auto_encoder:
            visualize_auto_encoder.write(result_string)


def predict_softmax(X, y, param):
    """TODO: Docstring for predict.

    :X: TODO
    :y: TODO
    :params: TODO
    :returns: TODO

    """
    tran_X = numpy.transpose(X.get_value())
    y      = y.get_value()
    prediction = numpy.exp(numpy.dot(param, tran_X)) \
            / numpy.sum(numpy.exp(numpy.dot(param, tran_X)), 0)

    prediction = [[int(x == max(z)) for x in z] for z in (numpy.transpose(prediction)).tolist()]

    print numpy.sum(prediction == y) / (y.shape[0] * y.shape[1] + 0.0)



def softmax_classify(X, y, options):
    """TODO: Docstring for softmax_classify.

    :X: TODO
    :y: TODO
    :options: TODO
    :returns: TODO

    """
    X = shared(value=add_bias_unit(X) / 10, name='X')
    y = shared(value=y, name='y')
    weight_decay = shared(value=options.decay, name='weight_decay')
    in_out_degree = [options.input, options.output]
    init_params = initial_params(in_out_degree)

    def cost_func_sm(params):
        """TODO: Docstring for cost_func_ld.

        :params: TODO
        :X: TODO
        :y: TODO
        :weight_decay: TODO
        :returns: TODO

        """
        # params in theano.
        theta1 = params[0]
        m      = shared(value=X.get_value().shape[0], name='m')
        tran_X = X.T

        z          = T.dot(theta1, tran_X)
        J          = (-1.0 / m) \
                * T.sum(T.log2(T.exp(T.sum((T.dot(y, theta1) * X), 1)) / T.sum(T.exp(z), 0))) \
                + (weight_decay / (2.0 * m)) * T.sum(theta1 ** 2.0)

        collector  = theano.function([], [J,
                                        T.grad(J, theta1),])

        all_result  = collector()

        J, grads    = all_result[0], all_result[1:]

        return J, grads

    start_time = time()

    params = gradient_descent(cost_func_sm, init_params, options)[0].get_value()

    end_time = time()

    predict_softmax(X, y, params)

    sio.savemat('./parameters/softmax' + str(options.id), {
            'weight': params,})

    print 'Training time of sparse linear decoder: %f minutes.' \
            %((end_time - start_time) / 60.0)
    print 'Training accuracy'

    return 5


def fill_feature_dict(folder, exclude_file=[]):
    """TODO: Docstring for fill_feature_dict.

    :all_files: TODO
    :exclude_file: TODO
    :returns: TODO

    """
    keywords = {}
    for filename in [x for x in listdir(folder) if x[0] != '.']:
        with open(join(folder, filename), 'r') as code_file:
            all_words = get_feature(code_file)
        for word in all_words:
            keywords.setdefault(word, 1)

    print 'The number of keywords: %d' % (len(keywords))

    return keywords


def keyword_to_feature(keywords, orded_key, index):
    """TODO: Docstring for keyword_to_feature.

    :keywords: TODO
    :returns: TODO

    """
    return [keywords.setdefault(key_tuple[0], 0) for key_tuple in orded_key]


def get_feature(fh):
    """TODO: Docstring for get_featurefile_feature.

    :filename: TODO
    :returns: TODO

    """
    processed = re.sub('\w+\s*[!=<>:;]|\'.*\'|\".*\"|[\*#].*|//.*',
                       '', fh.read())

    all_words = [x for x in re.findall('[a-z]+', processed)
                 if len(x) > 1 and len(x) <= 10]

    return dict(((word, 1) for word in all_words))


def parse_files(src_folder, exclude_file=[]):
    """TODO: Docstring for parse_files.

    :folder: TODO
    :exclude_file: TODO
    :returns: TODO

    """
    X, y, all_keywords = [], [], {}
    all_files = [x for x in listdir(src_folder) if x[0] != '.']
    all_keywords = fill_feature_dict(src_folder, exclude_file)
    orded_key = sorted(all_keywords.iteritems(), key=lambda x: x[0])
    temp = [splitext(x)[1] for x in all_files if x[0] != '.']
    all_extension = list(set(temp))

    for one in all_files:
        index = operator.indexOf(all_extension, splitext(one)[1]) + 1
        with open(join(src_folder, one), 'r') as fh:
            keywords = get_feature(fh)
        X.append(keyword_to_feature(keywords, orded_key, index))
        y.append(index)

    sio.savemat(join(PARAM_FOLDER, 'sample'), {
            'input': X, 'label': y,
            })
    sio.savemat(join(PARAM_FOLDER, 'ae_extension'), {
            'all_extension': all_extension,
            })
    sio.savemat(join(PARAM_FOLDER, 'ae_keyword'), {
            'all_keywords': all_keywords,
            })

    return numpy.array(X), numpy.array(y)


def load_data():
    """TODO: Docstring for parse_multi_file.
    :returns: TODO

    """
    result = {}
    sio.loadmat(join(PARAM_FOLDER, 'sample'), mdict=result)
    X, y = result['input'], result['label']

    return numpy.array(X), numpy.array(y)


def init_dir():
    """TODO: Docstring for init_dir.
    :returns: TODO

    """
    dirs = ['./param/ae']

    for ldir in dirs:
        if not isdir(ldir):
            exists(ldir) and os.unlink(ldir)
            makedirs(ldir)


def main():
    """TODO: Docstring for main.
    :returns: TODO

    """
    theano.config.exception_verbosity = 'high'

    init_dir()

    if options.task == 'autoencoder':
        print 'Training autoencoder.'
        X, y = load_data()
        print 'Shape of X: %s; Shape of y: %s' % (X.shape, y.shape)
        auto_encode(X, y, X.shape[1], X.shape[1]*0.2)
    elif options.task == 'parse_files':
        parse_files('./train/ae')
    elif options.task == 'visualization':
        visualize_auto_encoder(options)
    else:
        print 'Routine.'
        X, y = load_data('./train/softmax/', options)
        softmax_classify(X, y, options)


if __name__ == '__main__':
    main()
