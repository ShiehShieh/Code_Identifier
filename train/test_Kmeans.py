from numpy import *
import time
import matplotlib.pyplot as plt
import Kmeans

print "step 1: load data..."
dataSet = []
fileIn = open('kmean_dataset.txt')
for line in fileIn.readlines():
	lineArr = line.strip().split('\t')
	dataSet.append([float(lineArr[0]), float(lineArr[1])])

print "step 2: clustering..."
dataSet = mat(dataSet)
k = 4
centroids, clusterAssment = Kmeans.kmeans(dataSet, k)

print "step 3: show the result..."
Kmeans.showCluster(dataSet, k, centroids, clusterAssment)
