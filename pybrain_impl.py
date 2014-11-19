from pybrain.tools.shortcuts import buildNetwork
from pybrain.datasets import SupervisedDataSet, ClassificationDataSet
from pybrain.supervised.trainers import BackpropTrainer
from pybrain.structure import TanhLayer, SigmoidLayer
from pybrain.structure import SoftmaxLayer

from debug.debug import debug, pdb

@debug
def get_data_set(filename='data.txt'):
	def onevsall(num):
		if num > out_dim:  # error
			pdb.set_trace()
		return [1 if num==i else 0 for i in range(out_dim)]
	raw = open(filename).read()
	lines = raw.split()
	array = [float(one) for one in lines[0].split(',')]
	in_dim = len(array) - 1
	DS = SupervisedDataSet(in_dim, out_dim)
	for line in lines:
		array = [float(one) for one in lines[0].split(',')]
		DS.appendLinked(array[:-1], onevsall(array[-1]))
	return DS, in_dim

@debug
def test():
	test_set,dimension = get_data_set('test.txt')
	errors = 0
	total = 0
	for inp, target in test_set:
		total += 1
		# pdb.set_trace()
		pred = max(enumerate(net.activate(inp)),key=lambda x:x[1])[0]
		y = max(enumerate(target),key=lambda x:x[1])[0]
		errors += int(pred!=y)
	return total, errors, errors/float(total)

in_dim = None
out_dim = 4

DS, in_dim = get_data_set()
net = buildNetwork(in_dim, 50, out_dim, bias=True, hiddenclass=SigmoidLayer)
trainer = BackpropTrainer(net, DS)
for _ in range(2):
	trainer.train()
test()
# only one/two tieration would yield 100% accuracy
# this is the implementation of train/test part using pybrain
# parse raw file to features [stored in data.txt and test.txt] is done by parse_file.py
# trainer.trainUntilConvergence()