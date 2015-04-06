#!/usr/bin/env python
# encoding: utf-8


import re
import json
import math
import cmath
import numpy
import theano
import operator
import scipy.io as sio
import theano.tensor as T
from util import *
from time import time
from operator import add
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
    b = theano.function([], [a, a.shape])

    print b()

    return 0.0


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
    if flag==1:
        return numpy.mean(numpy.equal(a>=threshold, b>=threshold))
    elif flag == 2:
        return numpy.mean(numpy.abs(a-b)<numpy.amax(a/10.))
    elif flag == 3:
        return numpy.mean(numpy.abs(a-b)<numpy.amax(a/10.))
    else:
        return numpy.mean(numpy.equal(a, b))


def sigmoid(z):
    """TODO: Docstring for sigmoid.

    :z: TODO
    :returns: TODO

    """
    return 1 / (1 + cmath.e**(-z))


def predict_sae(X, params):
    """TODO: Docstring for predict.

    :X: TODO
    :params: TODO
    :returns: TODO

    """
    pred = X
    for index in range(0, len(params)-1, 3):
        theta1, b1 = params[index], params[index+1]
        theta2, b2 = params[index+2], params[index+3]
        pred = numpy.dot(sigmoid(numpy.dot(pred, theta1) + b1), theta2) + b2

    return pred


@log_time
@embed_params(_iter_num=options.iter1, _alpha=options.alpha1,
              _decay=options.decay, _beta=options.beta, _rho=options.rho)
def auto_encode(X, _iter_num, _alpha, _decay, _beta, _rho):
    """TODO: Docstring for auto_encode.

    :returns: TODO

    """
    input_n = X.shape[1]
    hidden_n = X.shape[1]*0.5
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
        tmp = formula(X, params[0], params[1], params[2], params[3], m, _decay)
        J, grads = tmp[0], tmp[1:]
        return J, grads

    start_time = time()

    finale = gradient_descent(cost_func_ae, init_params, _iter_num, _alpha)

    print 'Training time of sparse linear decoder: %f minutes.' \
            %((time() - start_time) / 60.0)
    print 'The accuracy of ae: %f %% (threshold used)' \
            % (assess(X, predict_sae(X, finale), 1))
    print 'The accuracy of ae: %f %% (abs used)' \
            % (assess(X, predict_sae(X, finale), 2))

    # sio.savemat('./param/ae_weight_bias', {
    #         'weight': params[0], 'bias': params[1],
    #         })

    return finale[:2]


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


def predict_sm(X, params):
    """TODO: Docstring for predict.

    :X: TODO
    :y: TODO
    :params: TODO
    :returns: TODO

    """
    z = sigmoid(numpy.dot(X, params[0]) + params[1]).T
    pred = z / numpy.sum(z, 0)

    return pred.T


def be_onefold(matrix, axis):
    """TODO: Docstring for be_onefold.

    :matrix: TODO
    :axis: TODO
    :returns: TODO

    """
    maximun = numpy.amax(matrix, axis)

    return numpy.equal(matrix.T, maximun.T).T


@log_time
@embed_params(_iter_num=options.iter2, _alpha=options.alpha2,
              _decay=options.decay, _beta=options.beta, _rho=options.rho)
def softmax_classify(X, y, _iter_num,
                _alpha, _decay, _beta, _rho):
    """TODO: Docstring for softmax_classify.

    :X: TODO
    :y: TODO
    :options: TODO
    :returns: TODO

    """
    input_n, output_n = X.shape[1], y.shape[1]
    in_out_degree = [input_n, output_n]
    init_params = initial_params(in_out_degree)

    t_X, t_y = T.dmatrix(), T.dmatrix()
    t_weight_decay, t_m = T.dscalar(), T.dscalar()
    t_theta, t_b = T.dmatrix(), T.dvector()

    z = T.dot(t_X, t_theta) + t_b
    J = (-1.0 / t_m) \
            * T.sum(T.log2(T.exp(T.sum(z * t_y, 1)) / T.sum(T.exp(z), 1))) \
            + (t_weight_decay / (2.0 * t_m)) * T.sum(t_theta ** 2.0)

    formula = theano.function([t_X, t_y, t_theta, t_b, t_weight_decay, t_m],
                              [J, T.grad(J, t_theta), T.grad(J, t_b),])

    def cost_func_sm(params):
        result = formula(X, y, params[0], params[1], _decay, X.shape[0])
        J, grads = result[0], result[1:]
        return J, grads

    start_time = time()

    finale = gradient_descent(cost_func_sm, init_params, _iter_num, _alpha)

    print 'Training time of sparse linear decoder: %f minutes.' \
            %((time() - start_time) / 60.0)
    print 'The accuracy of sm: %f %% (threshold used)' \
            % (assess(y, be_onefold(predict_sm(X, finale), 1), 1))
    print 'The accuracy of sm: %f %% (abs used)' \
            % (assess(y, be_onefold(predict_sm(X, finale), 1), 2))

    # sio.savemat('./param/sm_weight_bias', {
    #         'weight': params[0], 'bias': params[1]
    #         })

    return finale[:2]


def stack_aes(X, y, layer):
    """TODO: Docstring for stack_aes.

    :layer: TODO
    :returns: TODO

    """
    params = []
    for i in range(layer):
        weight, bias = auto_encode(X)
        params.append(weight)
        params.append(bias)
        X = sigmoid(numpy.dot(X, weight) + bias)

    weight, bias = softmax_classify(X, y)
    params.append(weight)
    params.append(bias)

    return params


def predict_dl(X, params):
    """TODO: Docstring for predict_dl.

    :X: TODO
    :params: TODO
    :returns: TODO

    """
    pred = X
    for index in range(0, len(params)-2, 2):
        weight, bias = params[index], params[index+1]
        pred = sigmoid(numpy.dot(pred, weight) + bias)

    pred = predict_sm(pred, params[-2:])

    return pred


@log_time
@embed_params(_iter_num=options.iter3,
              _alpha=options.alpha3, _decay=options.decay)
def deep_learn(X, y, layer, _iter_num, _alpha, _decay):
    """TODO: Docstring for deep_learn.

    :X: TODO
    :y: TODO
    :_iter_num: TODO
    :_alpha: TODO
    :_decay: TODO
    :returns: TODO

    """
    init_params = stack_aes(X, y, layer)

    t_X, t_y, t_z = T.dmatrix(), T.dmatrix(), T.dmatrix()
    t_m, t_weight_decay, t_b = T.dscalar(), T.dscalar(), T.dscalar()
    t_params = reduce(add, [[T.dmatrix(), T.dvector()] for i in range(len(init_params)/2)])

    t_z = t_X
    for i in range(0, len(t_params)-2, 2):
        t_z = T.nnet.sigmoid(T.dot(t_z, t_params[i])+t_params[i+1])
    t_z = T.dot(t_z, t_params[-2]) + t_params[-1]
    J = (-1.0 / t_m) \
            * T.sum(T.log2(T.exp(T.sum(t_z * t_y, 1)) / T.sum(T.exp(t_z), 1))) \
            + (t_weight_decay / (2.0 * t_m)) * \
            T.sum(reduce(add, [T.sum(param ** 2.0) for param in t_params]))

    formula = theano.function([t_X, t_y] + t_params + [t_weight_decay, t_m],
                              [J] + [T.grad(J, param) for param in t_params])

    def cost_func_sm(params):
        exec compile('tmp = formula(X, y, '+
                     ''.join(['params[%d], ' % (index)
                              for index in range(len(params))])+
                     '_decay, X.shape[0])',
                     '', 'exec') in {'formula': formula, 'X': X, 'y': y,
                                     '_decay': _decay, 'tmp': None}, locals()
        J, grads = tmp[0], tmp[1:]
        return J, grads

    start_time = time()

    finale = gradient_descent(cost_func_sm, init_params, _iter_num, _alpha)

    print 'Training time of sparse linear decoder: %f minutes.' \
            %((time() - start_time) / 60.0)
    print 'The accuracy of dl: %f %% (threshold used)' \
            % (assess(y, be_onefold(predict_dl(X, finale), 1), 1))
    print 'The accuracy of dl: %f %% (abs used)' \
            % (assess(y, be_onefold(predict_dl(X, finale), 1), 2))

    return finale


def fill_feature_dict(folder):
    """TODO: Docstring for fill_feature_dict.

    :all_files: TODO
    :returns: TODO

    """
    keywords = {}
    for filename in [x for x in listdir(folder) if x[0] != '.']:
        with open(join(folder, filename), 'r') as code_file:
            all_words = get_feature(code_file)
        for word in all_words:
            keywords.setdefault(word, 1)

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
    processed = re.sub('\'.*\'|\".*\"|[\*#].*|//.*|\"{3}.*|\'{3}.*|\w+\s*[!=<>:;]+|\w*_\w*|.*[A-Z].*',
                       '', fh.read())

    all_words = [x for x in re.findall('[a-z]+', processed)
                 if len(x) > 1 and len(x) <= 20]

    return dict(((word, 1) for word in all_words))


def precision_recall(y, y_pred):
    """TODO: Docstring for precision_recall.

    :y: TODO
    :y_pred: TODO
    :returns: TODO

    """
    print y
    print y_pred
    TP = numpy.sum((y_pred==1)&(y==1))
    FP = numpy.sum((y_pred==1)&(y==0))
    FN = numpy.sum((y_pred==0)&(y==1))
    print TP
    print FP
    print FN

    print 'precision is : %f %%' % (TP / float(TP+FP))
    print 'recall is : %f %%' % (TP / float(TP+FN))


def parse_file_key(src_folder, tt, all_keywords=None, all_extension=None):
    """TODO: Docstring for parse_file_key.

    :folder: TODO
    :returns: TODO

    """
    X, y = [], []
    all_files = [x for x in listdir(src_folder) if x[0] != '.']
    if all_keywords is None:
        all_keywords = fill_feature_dict(src_folder)
    if all_extension is None:
        temp = [splitext(x)[1] for x in all_files if x[0] != '.']
        all_extension = list(set(temp))
    orded_key = sorted(all_keywords.iteritems(), key=lambda x: x[0])
    all_extension = sorted(all_extension)

    for one in all_files:
        index = operator.indexOf(all_extension, splitext(one)[1])
        with open(join(src_folder, one), 'r') as fh:
            keywords = get_feature(fh)
        X.append(keyword_to_feature(keywords, orded_key, index))
        y.append([int(i == index) for i in range(len(all_extension))])

    print 'The number of keywords: %d' % (len(all_keywords))
    print 'The number of label: %d' % (len(all_extension))

    with open('all_keywords.txt', 'w') as tmp:
        tmp.write(str(all_keywords))

    with open('all_extension.txt', 'w') as tmp:
        tmp.write(str(all_extension))

    sio.savemat(tt+'_sample', {
            'input': X, 'label': y,
            })
    with open(join(PARAM_FOLDER, 'extension'), 'w') as tmp:
        tmp.write(json.dumps(all_extension))
    with open(join(PARAM_FOLDER, 'keyword'), 'w') as tmp:
        tmp.write(json.dumps(all_keywords))

    return numpy.array(X), numpy.array(y)


def parse_file_byte(src_folder, tt, all_keywords=None, all_extension=None):
    """TODO: Docstring for parse_file_byte.

    :returns: TODO

    """
    X, y = [], []
    all_files = [x for x in listdir(src_folder) if x[0] != '.']
    if all_extension is None:
        temp = [splitext(x)[1] for x in all_files if x[0] != '.']
        all_extension = list(set(temp))
    all_extension = sorted(all_extension)

    for one in all_files:
        index = operator.indexOf(all_extension, splitext(one)[1])
        with open(join(src_folder, one), 'r') as fh:
            feature = [ord(i) for i in fh.read()[:900]]
        X.append(feature)
        y.append([int(i == index) for i in range(len(all_extension))])

    print 'The number of feature: %d' % (900)
    print 'The number of label: %d' % (len(all_extension))

    with open('all_extension.txt', 'w') as tmp:
        tmp.write(str(all_extension))

    sio.savemat(tt+'_sample', {
            'input': X, 'label': y,
            })
    with open(join(PARAM_FOLDER, 'extension'), 'w') as tmp:
        tmp.write(json.dumps(all_extension))
    with open(join(PARAM_FOLDER, 'keyword'), 'w') as tmp:
        tmp.write(json.dumps(all_keywords))

    return numpy.array(X), numpy.array(y)


def load_data(fn):
    """TODO: Docstring for parse_multi_file.
    :returns: TODO

    """
    result = {}
    sio.loadmat(fn, mdict=result)
    X, y = result['input'], result['label']

    return X, y


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

    if options.feature_type == 'keyword':
        parse_file = parse_file_key
    else:
        parse_file = parse_file_byte

    if options.task == 'ae':
        print 'Training autoencoder.'
        X, y = load_data(join(PARAM_FOLDER, options.task+'_sample'))
        print 'Shape of X: %s; Shape of y: %s' % (X.shape, y.shape)
        auto_encode(X)
    elif options.task == 'pfn':
        parse_file(options.src, join(PARAM_FOLDER, options.tt))
    elif options.task == 'pfo':
        with open(join(PARAM_FOLDER, 'keyword'), 'r') as tmp:
            key = json.load(tmp)
        with open(join(PARAM_FOLDER, 'extension'), 'r') as tmp:
            ext = json.load(tmp)
        parse_file(options.src, join(PARAM_FOLDER, options.tt), dict(key), ext)
    elif options.task == 'visualization':
        visualize_auto_encoder(options)
    elif options.task == 'saes':
        print 'Training stacked auto encoder.'
        X, y = load_data(join(PARAM_FOLDER, options.task+'_sample'))
        print 'Shape of X: %s; Shape of y: %s' % (X.shape, y.shape)
        stack_aes(X, y, 2)
    elif options.task == 'sm':
        print 'Training softmax_classifier.'
        X, y = load_data(join(PARAM_FOLDER, options.task+'_sample'))
        print 'Shape of X: %s; Shape of y: %s' % (X.shape, y.shape)
        softmax_classify(X, y)
    elif options.task == 'dl':
        print 'Training deep neural network.'
        X, y = load_data(join(PARAM_FOLDER, options.task+'_sample'))
        print 'Shape of X: %s; Shape of y: %s' % (X.shape, y.shape)
        deep_learn(X, y, 2)
    else:
        X, y = load_data(join(PARAM_FOLDER, 'dl_sample'))
        params = deep_learn(X, y, 2)
        test_X, test_y = load_data(join(PARAM_FOLDER, 'test_sample'))

        print '----------'
        print 'The accuracy of dl: %f %% (threshold used)' \
                % (assess(test_y, be_onefold(predict_dl(test_X, params), 1), 1))
        print 'The accuracy of dl: %f %% (abs used)' \
                % (assess(test_y, be_onefold(predict_dl(test_X, params), 1), 2))
        precision_recall(test_y, be_onefold(predict_dl(test_X, params), 1))


if __name__ == '__main__':
    main()
