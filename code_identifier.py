#!/usr/bin/env python
# encoding: utf-8


import theano
import numpy
import scipy
import scipy.io as sio
import theano.tensor as T
from functools import wraps
from optparse import OptionParser


# Global variable.
FILESIZE = 100000


USAGE   = "usage: %prog [options] arg1 arg2"
VERSION = 'v1.0.0'


def wrap_cost_func(activate, X, y, weight_decay, beta, rho):
    """TODO: Docstring for wrap_cost_func.

    :activate: TODO
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
            J, grads = cost_func(params, activate, X, y, weight_decay, beta, rho)

            return J, grads

        return wrapper

    return wrap_up


def get_options():
    """TODO: Docstring for get_options.
    :returns: TODO

    """
    parser = OptionParser(usage=USAGE, version=VERSION)

    parser.add_option('-w', '--weight', action='store', type='string',
            help='The weight file.',
            dest='weight_file')
    parser.add_option('-c', '--config', action='store', type='string',
            help='The config file.',
            dest='config_file')
    parser.add_option('-f', '--file', action='store', type='string',
            help='the file you want to make a prediction.',
            dest='filename')
    parser.add_option('-m', '--multi', action='store_true', dest='multi',
            help='If this symbol is set, train the algorithem by all file \
            in this directory.')
    parser.add_option('-t', '--test', action='store_true', dest='test',
            help='Test.')

    return parser.parse_args()


def kl_divergence(rho, rho_cap):
    """TODO: Docstring for kl_divergence.

    :rho: TODO
    :rho_cap: TODO
    :returns: TODO

    """
    kl = T.sum(rho * T.log2(rho / rho_cap) \
            + (1 - rho) * T.log2((1 - rho) / (1 - rho_cap)))

    return kl


def gradient_descent(cost_func,
                    params,
                    options):
    """TODO: Docstring for gradient_descent.

    :gradient_descent(cost_func: TODO
    :params: TODO
    :options: TODO
    :returns: TODO

    """
    for i in range(options.times):
        J, grads = cost_func(params)
        for index, param in grads:
            params[index] = params[index] - param


def auto_encode(row_num, column_num, raw_features):
    """TODO: Docstring for auto_encode.

    :row_num: TODO
    :column_num: TODO
    :raw_features: TODO
    :returns: TODO

    """
    pass


def softmax_classify(input_num, output_num, input_data):
    """TODO: Docstring for softmax_classify.

    :input_num: TODO
    :output_num: TODO
    :input_data: TODO
    :returns: TODO

    """
    pass


def load_data():
    """TODO: Docstring for load_data.
    :returns: TODO

    """
    pass


if __name__ == '__main__':
    (options, args) = get_options()

    value           = T.dmatrix('value')
    result          = 1 / (1 + T.exp(value))
    sigmoid         = theano.function([value], result)

    X, y            = load_data()
    weight_decay    = 0.5
    beta, rho       = 0.5, 0.05

    @wrap_cost_func(sigmoid, X, y, weight_decay, beta, rho)
    def cost_func_ld(params,
                    activate,
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
        weights, bs = params[0 : len(params) / 2], params[len(params) / 2 : ]
        bias1       = bs[0]
        bias2       = bs[1]
        theta1      = weights[0]
        theta2      = weights[1]
        m           = T.shape(X)[0]
        y           = T.transpose(X)
        neuron      = activate(T.dot(theta1, T.transpose(X)) + bias1)
        prediction  = T.dot(theta2, neuron) + bias2
        rho_cap     = T.sum(neuron, 0) / m

        J           = (1 / m) * T.sum((prediction - y) ** 2) \
                        + (weight_decay / (2 * m)) * (T.sum(theta1) + T.sum(theta2)) \
                        + beta * kl_divergence(rho, rho_cap)
        grads       = [T.grad(J, theta1), T.grad(J, theta2), T.grad(J, bias1), T.grad(J, bias2)]

        return J, grads
