#!/usr/bin/env python
# encoding: utf-8


import sys
import numpy as np
import matplotlib.cm as cm
import matplotlib.pyplot as plt
from optparse import OptionParser
from sklearn.manifold import Isomap
from sklearn.datasets import load_files
from sklearn.feature_extraction.text import TfidfVectorizer


USAGE   = "usage: e.g. python %prog "
VERSION = 'v1.0.0'


def get_options():
    """TODO: Docstring for get_options.
    :returns: TODO

    """
    parser = OptionParser(usage=USAGE, version=VERSION)

    parser.add_option('--fold', action='store', type='string',
                      help='The fold contain the dataset.', dest='fold')
    parser.add_option('--3d', action='store_true',
                      help='Plot 3D.', dest='dime', default=False)

    len(sys.argv) == 1 and exit(parser.print_help())

    return parser.parse_args()


def plot_2d(dataset):
    """TODO: Docstring for plot_2d.
    :returns: TODO

    """
    iso = Isomap(n_components=2)
    projected = iso.fit_transform(dataset.data.toarray())

    print 'projected: sample: %s, feature: %s'\
            % (projected.shape[0], projected.shape[1])

    all_scatter = []
    colors = cm.rainbow(np.linspace(0, 1, len(dataset.target_names)), alpha=0.5)
    for i in range(len(dataset.target_names)):
        points = projected[dataset.target==i,:]
        cur = plt.scatter(points[:,0], points[:,1], color=colors[i],
                          edgecolor='k', lw=0.6,
                          vmin=0, vmax=len(dataset.target_names))
        all_scatter.append(cur)
    plt.legend(all_scatter, dataset.target_names,
               loc='lower left', scatterpoints=1)
    plt.clim(-0.5, 9.5)
    plt.savefig('isomap2d', dpi=500)


def plot_3d(dataset):
    """TODO: Docstring for plot_3d.
    :returns: TODO

    """
    from mpl_toolkits.mplot3d import Axes3D

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    iso = Isomap(n_components=3)
    projected = iso.fit_transform(dataset.data.toarray())

    print 'projected: sample: %s, feature: %s'\
            % (projected.shape[0], projected.shape[1])

    all_scatter = []
    colors = cm.rainbow(np.linspace(0, 1, len(dataset.target_names)), alpha=0.5)
    for i in range(len(dataset.target_names)):
        points = projected[dataset.target==i,:]
        cur = ax.scatter(points[:,0], points[:,1], points[:,2],
                          color=colors[i], edgecolor='k', lw=0.1,
                          vmin=0, vmax=len(dataset.target_names))
        all_scatter.append(cur)
    ax.legend(all_scatter, dataset.target_names,
               loc='lower left', scatterpoints=1)
    plt.savefig('isomap3d', dpi=500)
    plt.show()

    return True


def main():
    """TODO: Docstring for main.
    :returns: TODO

    """
    (options, args) = get_options()

    dataset = load_files(options.fold)
    tokenizor = TfidfVectorizer(ngram_range=(1, 2), decode_error='ignore',
                                min_df=0.1, max_df=0.9)
    dataset.data = tokenizor.fit_transform(dataset.data)
    
    print 'original: sample: %s, feature: %s'\
            % (dataset.data.shape[0], dataset.data.shape[1])

    options.dime and plot_3d(dataset) or plot_2d(dataset)


if __name__ == '__main__':
    main()
