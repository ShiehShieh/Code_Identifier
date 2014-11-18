

from numpy import *
import time
import matplotlib.pyplot as plt

def euclDistance(vector1, vector2):
	return sqrt( sum( power(vector2-vector1, 2) ) )

def initCentroids(dataSet, k):
	numSamples, dim=dataSet.shape
	centroids = zeros((k, dim))
	for i in range(k):
		index = int( random.uniform(0, numSamples) )
		centroids[i, :] = dataSet[index, :]
	return centroids

def kmeans(dataSet, k):
	numSamples = dataSet.shape[0]
	clusterAssment = mat( zeros((numSamples, 2)) )
	clusterChanged = True

	centroids = initCentroids(dataSet, k)
	print "initial centroids:\n",centroids

	while clusterChanged:
		clusterChanged = False
		for i in xrange(numSamples):
			minDist = 100000.0
			minIndex = 0
			for j in range(k):
				distance = euclDistance(centroids[j, :], dataSet[i,:])
				if distance < minDist:
					minDist = distance
					minIndex = j
			
			if clusterAssment[i, 0] != minIndex:
				clusterChanged = True
				clusterAssment[i,:] = minIndex, minDist**2

		for j in range(k):
			pointsInCluster = dataSet[nonzero(clusterAssment[:,0].A ==j)[0]]
			centroids[j,:] = mean(pointsInCluster, axis=0)
	
	print "cluster complete"
	return centroids, clusterAssment

def showCluster(dataSet, k, centroids, clusterAssment):
	numSamples ,dim = dataSet.shape
	if dim != 2:
		print "dimension is not 2"
		return 1
	
	mark = ['or', 'ob', 'og', 'ok', '^r', '+r', 'sr', 'dr', '<r', 'pr']
	if k> len(mark):
		print "k is too large"
		return 1
	
	for i in xrange(numSamples):
		markIndex = int(clusterAssment[i,0])
		plt.plot(dataSet[i,0], dataSet[i,1], mark[markIndex])

	mark = ['Dr', 'Db', 'Dg', 'Dk', '^b', '+b', 'sb', 'db', '<b', 'pb']  
	for i in range(k):  
		plt.plot(centroids[i, 0], centroids[i, 1], mark[i], markersize = 12)  
  
	plt.show()  
