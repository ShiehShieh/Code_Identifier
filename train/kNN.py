

from numpy import *
import operator
import os

def createDataSet():
	group = array([ [1.0, 0.9], [1.0, 1.0], [0.1, 0.2], [0.0, 0.1]])
	labels = ['A', 'A', 'B', 'B']

	print "Group:\n",group
	print "Labels:", labels
	return group, labels

def kNNClassify(newInput, dataSet, labels, k):
	numSamples = dataSet.shape[0]

	newTile = tile(newInput, (numSamples ,1))

	diff = newTile - dataSet
	squaredDiff = diff ** 2
	squaredDist = sum(squaredDiff, axis = 1)
	distance = squaredDist ** 0.5

	sortedDistIndices = argsort(distance)

	classCount = {} #define a dictionary
	for i in xrange(k):
		voteLabel = labels[sortedDistIndices[i]]

		classCount[voteLabel] = classCount.get(voteLabel, 0)+1
	
	maxCount = 0
	for key, value in classCount.items():
		if value > maxCount:
			maxCount = value
			maxIndex = key

	return maxIndex

def img2vector(filename):
	rows = 32
	cols = 32
	imgVector = zeros((1, rows * cols))
	fileIn = open(filename)
	for row in xrange(rows):
		lineStr = fileIn.readline()
		for col in xrange(cols):
			imgVector[0, row * 32 + col] = int(lineStr[col])
	
	return imgVector
def loadDataSet():
	print ""
	dataSetDir = ''
	trainingFileList = os.listdir(dataSetDir + 'trainingDigits')
	numSamples = len(trainingFileList)

	train_x = zeros((numSamples, 1024))
	train_y = []
	for i in xrange(numSamples):
		filename = trainingFileList[i]

		train_x[i, :] = img2vector(dataSetDir + 'trainingDigits/%s' % filename) 

		label = int(filename.split('_')[0])
		train_y.append(label)

	print "---Getting testing set..."
	testingFileList = os.listdir(dataSetDir + 'testDigits')
	numSamples = len(testingFileList)
	test_x = zeros((numSamples, 1024))
	test_y = []
	for i in xrange(numSamples):
		filename = testingFileList[i]

		test_x[i, :] = img2vector(dataSetDir + 'testDigits/%s' % filename) 

		label = int(filename.split('_')[0])
		test_y.append(label)

	return train_x, train_y, test_x, test_y

def testHandWritingClass():
	print "step 1: load data..."
	train_x, train_y, test_x, test_y = loadDataSet()

	print "step 2: training..."
	pass

	print "step 3: testing..."
	numTestSamples = test_x.shape[0]
	matchCount = 0
	for i in xrange(numTestSamples):
		predict = kNNClassify(test_x[i], train_x, train_y, 3)
		print "predict:", predict 
		print "value:", test_y[i]
		if predict == test_y[i]:
			matchCount += 1
		else:
			print "predict:", predict 
			print "value:", test_y[i]

	accuracy = float(matchCount) / numTestSamples

	print "step 4: show the result..."
	print 'The classify accuracy is: %.2f%%' % (accuracy * 100)

if __name__ == '__main__':
	import kNN
	from numpy import *

	dataSet, labels = kNN.createDataSet()

	testX = array([0.2, 0.01])
	k = 3
	outputLabel = kNN.kNNClassify(testX, dataSet, labels, 3)
	print "Your input is", testX, "and classified to class:", outputLabel

	kNN.testHandWritingClass()
