import sys
import pickle
from optparse import OptionParser
from sklearn import metrics
from sklearn.svm import LinearSVC
from sklearn.pipeline import Pipeline
from sklearn.datasets import load_files
from sklearn.grid_search import GridSearchCV
from sklearn.cross_validation import train_test_split
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

    len(sys.argv) == 1 and exit(parser.print_help())

    return parser.parse_args()


def main():
    """TODO: Docstring for main.
    :returns: TODO

    """
    (options, args) = get_options()

    dataset = load_files(options.fold)
    x_train, x_test, y_train, y_test = train_test_split(
            dataset.data, dataset.target, test_size=0.4)

    clf = Pipeline([
            ('vect', TfidfVectorizer(decode_error='ignore',
                                     min_df=0.1, max_df=0.9)),
            ('svc', LinearSVC())])
    parameters = {
            'vect__ngram_range': [(1,1), (1,2)],
            'svc__C': [i*0.5 for i in range(1, 20)],
            }

    gs_clf = GridSearchCV(clf, parameters, n_jobs=6)
    gs_clf = gs_clf.fit(dataset.data, dataset.target)

    y_pred = gs_clf.predict(x_test)

    best_param, score, _ = max(gs_clf.grid_scores_, key=lambda x: x[1])
    print best_param, score

    print 'n_samples: %d' % len(dataset.data)
    print 'test: %d' % (len(dataset.data)*0.4)
    print metrics.classification_report(y_test, y_pred,
                                        target_names=dataset.target_names)
    print metrics.confusion_matrix(y_test, y_pred)

    with open('./learning_result.modle', 'wb') as fd:
        result = {
                'target_names': dataset.target_names,
                'clf': gs_clf,
                }
        pickle.dump(result, fd)


if __name__ == '__main__':
    main()
