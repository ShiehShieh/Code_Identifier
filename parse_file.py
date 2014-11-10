#!/usr/bin/env python
# encoding: utf-8


import re
import os
import sys
import json
import operator
import cmath
from scipy import io
from numpy import dot
from numpy import loadtxt
from numpy import array
from operator import itemgetter
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


def sigmoid(z):
    """TODO: Docstring for sigmoid.

    :z: TODO
    :returns: TODO

    """
    return 1 / (1 + cmath.e**(-z))


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
    parser.add_option('-m', '--multi', action='store_true', dest='multi',
            help='If this symbol is set, train the algorithem by all file \
            in this directory.')
    parser.add_option('-t', '--test', action='store_true', dest='test',
            help='Test.')

    return parser.parse_args()


def predict(options, args):
    """TODO: Docstring for main.
    :returns: TODO

    """
    argument = load_argument(options.weight_file, options.config_file)

    input_data = loadtxt('unknow.txt', delimiter=',')
    x = input_data[0:-1]
    y = input_data[-1]

    with open('all_extension.txt', 'r') as extension_file:
        all_extension = json.loads(extension_file.read())

    result =  sigmoid(dot(argument.theta2, sigmoid(array([1] + list(dot(argument.theta1, array([1] + list(x))))))))

    rate = max(list(result))

    print 'The correct rate is: %f' %(rate)
    print 'The extension of the file should be \"%s\"' %(all_extension[operator.indexOf(result, rate)])


def create_predict_file(filename, all_extension, all_keywords, exclude_file):
    """TODO: Docstring for predict.

    :filename: TODO
    :exclude_file: TODO
    :returns: TODO

    """
    keywords    = {}
    single_file = [filename]
    index       = operator.indexOf(all_extension, os.path.splitext(filename)[1]) + 1
    keywords    = fill_feature_dict(single_file, './unknow/')
    result      = keyword_to_feature(keywords, all_keywords, index)

    with open('unknow.txt', 'w') as unknow_file:
        unknow_file.write(result + os.linesep)


def test(all_extension, all_keywords, exclude_file=[]):
    """TODO: Docstring for parse_multi_file.
    :returns: TODO

    """
    all_files     = [x for x in os.listdir('./test') if x[0] != '.']

    with open('test.txt', 'w') as test_file:
        for one in all_files:
            single_list = [one]
            index       = operator.indexOf(all_extension, os.path.splitext(one)[1]) + 1
            keywords    = fill_feature_dict(single_list, './test/')
            result      = keyword_to_feature(keywords, all_keywords, index)

            test_file.write(result + os.linesep)


def fill_feature_dict(all_files, folder, exclude_file=[]):
    """TODO: Docstring for fill_feature_dict.

    :all_files: TODO
    :exclude_file: TODO
    :returns: TODO

    """
    keywords = {}

    for filename in all_files:
        if os.path.splitext(filename)[1] not in exclude_file:
            filename = folder + filename
            with open(filename, 'r') as code_file:
                # remove the string and word in the right-hand side of [!=<>:;]
                processed = re.sub('\w+\s*[!=<>:;]', '', code_file.read())
                processed = re.sub('\'.*\'', '', processed)
                processed = re.sub('\".*\"', '', processed)

                all_words = [x for x in re.findall('[A-Za-z]+', processed) if len(x) > 1 and len(x) <= 10]
                for word in all_words:
                    keywords.setdefault(word, 0)
                    keywords[word] += 1

    return keywords


def keyword_to_feature(keywords, all_keywords, index):
    """TODO: Docstring for keyword_to_feature.

    :keywords: TODO
    :returns: TODO

    """
    result = ''
    all_keywords_order = sorted(all_keywords.iteritems(), key=lambda x: x[0], reverse=False)

    for key_tuple in all_keywords_order:
        result += str(keywords.setdefault(key_tuple[0], 0)) + ','

    result += str(index)

    return result


def count_one_type(extension):
    """TODO: Docstring for count_one_type.

    :extension: TODO
    :returns: TODO

    """
    keywords  = {}
    all_files = [x for x in os.listdir('./train') if os.path.splitext(x)[1] == extension]
    keywords  = fill_feature_dict(all_files, './train/')

    return keywords


def parse_multi_file(output_file, exclude_file):
    """TODO: Docstring for parse_multi_file.
    :returns: TODO

    """
    all_keywords  = {}
    all_files     = [x for x in os.listdir('./train') if x[0] != '.']
    all_keywords  = fill_feature_dict(all_files, './train/', exclude_file)
    temp          = [os.path.splitext(x)[1] for x in all_files if x[0] != '.']
    all_extension = list(set(temp))

    for one in all_files:
        single_list = [one]
        index       = operator.indexOf(all_extension, os.path.splitext(one)[1]) + 1
        keywords    = fill_feature_dict(single_list, './train/')
        result      = keyword_to_feature(keywords, all_keywords, index)

        output_file.write(result + os.linesep)

    with open('all_extension.txt', 'w') as extension_file:
        extension_file.write(json.dumps(all_extension))

    with open('all_keywords.txt', 'w') as keyword_file:
        keyword_file.write(json.dumps(all_keywords))

    with open('oct_extension.txt', 'w') as oct_extension:
        for extension in all_extension:
            oct_extension.write(extension + os.linesep)


def main():
    """TODO: Docstring for main.
    :returns: TODO

    """
    (options, args) = get_options()

    exclude_file = ['.swp', '.mat', '']

    try:
        with open('all_extension.txt', 'r') as extension_file:
            all_extension = json.loads(extension_file.read())

        with open('all_keywords.txt', 'r') as keyword_file:
            all_keywords = json.loads(keyword_file.read())
    except IOError, e:
        pass

    if options.multi:
        with open('data.txt', 'w') as output_file:
            parse_multi_file(output_file,
                    exclude_file)
    elif options.test:
        test(all_extension, all_keywords)
    else:
        create_predict_file(options.filename,
                all_extension,
                all_keywords,
                exclude_file)
        predict(options, args)

if __name__ == '__main__':
    main()
