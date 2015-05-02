#!/usr/bin/env python
# encoding: utf-8


import sys
import pickle
from optparse import OptionParser


USAGE   = "usage: e.g. python %prog "
VERSION = 'v1.0.0'


def get_options():
    """TODO: Docstring for get_options.
    :returns: TODO

    """
    parser = OptionParser(usage=USAGE, version=VERSION)

    parser.add_option('-m', '--mode', action='store', type='string',
                      help='The mode.', dest='mode')
    parser.add_option('-f', '--file', action='store', type='string',
                      help='The unknown file.', dest='file')

    len(sys.argv) == 1 and exit(parser.print_help())

    return parser.parse_args()


def main():
    """TODO: Docstring for main.
    :returns: TODO

    """
    (options, args) = get_options()

    with open(options.file, 'r') as data_file:
        data = [data_file.read()]
    with open(options.mode, 'rb') as fd:
        result = pickle.load(fd)
        target_names = result['target_names']
        clf = result['clf']
        print 'The type of the file is: %s .' \
                % (target_names[clf.predict(data)])


if __name__ == '__main__':
    main()
