from time import time
from functools import wraps
from optparse import OptionParser


USAGE   = "usage: %prog [options] arg1 arg2"
VERSION = 'v1.0.0'


def get_options():
    """TODO: Docstring for get_options.
    :returns: TODO

    """
    FILESIZE  = 10000
    TARGET    = 200
    ITERATION = 50
    ALPHA     = 0.005
    SPARSITY  = 0.005
    WEIGHT    = 0.005
    RHO       = 0.005

    # kw = dict(((word, 1) for word in get_feature(open(join(folder, filename)))
    #            for filename in all_files))

    parser = OptionParser(usage=USAGE, version=VERSION)

    parser.add_option('-f', '--feature', action='store', type='int',
            help='The number of raw feature', default=FILESIZE, dest='n')
    parser.add_option('--i1', action='store', type='int',
            help='The number of iteration for ae', default=ITERATION,
            dest='iter1')
    parser.add_option('--i2', action='store', type='int',
            help='The number of iteration for sm', default=ITERATION,
            dest='iter2')
    parser.add_option('--i3', action='store', type='int',
            help='The number of iteration for dl', default=ITERATION,
            dest='iter3')
    parser.add_option('-w', '--weightdecay', action='store', type='float',
            help='The speed of weight decay', default=WEIGHT, dest='decay')
    parser.add_option('-r', '--rho', action='store', type='float',
            help='The mean of activation', default=RHO, dest='rho')
    parser.add_option('-l', '--learningrate', action='store', type='float',
            help='The speed of learning', default=ALPHA, dest='alpha')
    parser.add_option('-s', '--sparsity', action='store', type='float',
            help='The value of sparsity parameter', default=SPARSITY,
            dest='beta')
    parser.add_option('-T', '--task', action='store', type='string',
            help='The task.', default='', dest='task')
    parser.add_option('-t', '--target', action='store', type='string',
            help='The task parsed file will be used for.', dest='tt')
    parser.add_option('--src', action='store', type='string',
            help='Source folder.', dest='src')
    parser.add_option('-d', '--tf', action='store', type='string',
            help='The directory.', default='./train/', dest='target_folder')
    parser.add_option('-m', '--multi', action='store_true', dest='multi',
            help='If this symbol is set, train the algorithem by all file \
            in this directory.')

    return parser.parse_args()


def log_time(fn):
    """TODO: Docstring for log_time.

    :fn: TODO
    :returns: TODO

    """
    @wraps(fn)
    def wrapper(*args, **kwargs):
        start_time = time()

        result = fn(*args, **kwargs)

        end_time = time()
        print '%s -> Time used : %d\n' % (fn.__name__, end_time - start_time)

        return result

    return wrapper


def embed_params(**kwargs):
    """TODO: Docstring for embed_params.

    :**kwargs: TODO
    :returns: TODO

    """
    def decorator(fn):
        """TODO: Docstring for decorator.

        :fn: TODO
        :returns: TODO

        """
        @wraps(fn)
        def wrapper(*arg):
            """TODO: Docstring for wrapper.

            :*arg: TODO
            :returns: TODO

            """
            return fn(*arg, **kwargs)

        return wrapper

    return decorator
