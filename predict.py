#!/usr/bin/env python
# encoding: utf-8


from scipy import io
from numpy import dot
from numpy import loadtxt
from numpy import array
from optparse import OptionParser


USAGE   = "usage: %prog [options] arg1 arg2"
VERSION = 'v1.0.0'


class Argument(object):

    """Docstring for Argument. """

    def __init__(self, weight_file, config_file):
        """TODO: to be defined1.

        :weight_file: TODO
        :config_file: TODO

        """
        self.weight_file = weight_file
        self.config_file = config_file
        self.input_layer_size = io.loadmat(config_file)['input_layer_size']
        self.hidden_layer_size = io.loadmat(config_file)['hidden_layer_size']
        self.num_labels = io.loadmat(config_file)['num_labels']
        self.theta1 = io.loadmat(weight_file)['Theta1']
        self.theta2 = io.loadmat(weight_file)['Theta2']


def load_argument(weight_file, config_file):
    """TODO: Docstring for load_weight.

    :weight_file: TODO
    :config_file: TODO
    :returns: TODO

    """
    argument = Argument(weight_file, config_file)

    return argument


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

    return parser.parse_args()


def main():
    """TODO: Docstring for main.
    :returns: TODO

    """
    (options, args) = get_options()

    argument = load_argument(options.weight_file, options.config_file)

    input_data = loadtxt(options.filename, delimiter=',')
    x = input_data[0:-1]
    y = input_data[-1]

    print dot(argument.theta2, array([1] + list(dot(argument.theta1, array([1] + list(x))))))

if __name__ == '__main__':
    main()

