#!/usr/bin/env python
# encoding: utf-8


import re
import os
import sys
import json
import operator
from operator import itemgetter
from optparse import OptionParser


USAGE   = "usage: %prog [options] arg1 arg2"
VERSION = 'v1.0.0'


def predict(filename, all_extension, all_keywords, exclude_file):
    """TODO: Docstring for predict.

    :filename: TODO
    :exclude_file: TODO
    :returns: TODO

    """
    keywords    = {}
    single_file = [filename]
    index       = operator.indexOf(all_extension, os.path.splitext(filename)[1]) + 1
    keywords    = fill_feature_dict(single_file, './test/')
    result      = keyword_to_feature(keywords, all_keywords, index)

    with open('new_file.txt', 'w') as new_file:
        new_file.write(result + os.linesep)


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
                all_words = [x for x in re.findall('[A-Za-z]+', code_file.read()) if len(x) > 1 and len(x) <= 10]
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
    all_files = [x for x in os.listdir('./file_folder') if os.path.splitext(x)[1] == extension]
    keywords  = fill_feature_dict(all_files, './file_folder/')

    return keywords


def parse_multi_file(output_file, exclude_file):
    """TODO: Docstring for parse_multi_file.
    :returns: TODO

    """
    all_keywords  = {}
    all_files     = [x for x in os.listdir('./file_folder') if x[0] != '.']
    all_keywords  = fill_feature_dict(all_files, './file_folder/', exclude_file)
    temp          = [os.path.splitext(x)[1] for x in all_files if x[0] != '.']
    all_extension = list(set(temp))

#    for index, extension in enumerate(all_extension):
#        result = ''
#        keywords = count_one_type(extension)
#        for key in all_keywords:
#            result += str(keywords.setdefault(key, 0)) + ','
#
#        result += str(index + 1)
#
#        output_file.write(result + os.linesep)

    for one in all_files:
        single_list = [one]
        index       = operator.indexOf(all_extension, os.path.splitext(one)[1]) + 1
        keywords    = fill_feature_dict(single_list, './file_folder/')
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
    parser = OptionParser(usage=USAGE, version=VERSION)

    parser.add_option('-m', '--multi', action='store_true', dest='multi',
            help='If this symbol is set, train the algorithem by all file \
            in this directory.')
    parser.add_option('-f', '--file', action='store', type='string',
            help='the file you want to use to feed the neural netword.',
            dest='filename')
    parser.add_option('-t', '--test', action='store_true', dest='test',
            help='Test.')

    (options, args) = parser.parse_args()
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
        predict(options.filename,
                all_extension,
                all_keywords,
                exclude_file)

if __name__ == '__main__':
    main()
