from numpy import *
import matplotlib.pyplot as plt
import time
import LogisticRegression as lr

def loadData():

	train_x = []
	train_y = []
	fileIn = open('testSet_LR.txt')
	for line in fileIn.readlines():
		lineArr = line.strip().split()
		train_x.append([1.0, float(lineArr[0]), float(lineArr[1])])
		train_y.append(float(lineArr[2]))
	return mat(train_x), mat(train_y).transpose()


print "step 1: load data..."
train_x, train_y = loadData()
test_x = train_x; test_y = train_y

print "step 2: training..."
opts = {'alpha': 0.01, 'maxIter': 1000, 'optimizeType': 'gradDescent'}
optimalWeights = lr.trainLogRegres(train_x, train_y, opts)

print "step 3: testing..."
accuracy = lr.testLogRegres(optimalWeights, test_x, test_y)

print "step 4: show the result..."	
print 'The classify accuracy is: %.3f%%' % (accuracy * 100)
lr.showLogRegres(optimalWeights, train_x, train_y) 
