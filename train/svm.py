from numpy import *
import time
import matplotlib.pyplot as plt 


def calcKernelValue(matrix_x, sample_x, kernelOption):
	kernelType = kernelOption[0]
	numSamples = matrix_x.shape[0]
	kernelValue = mat(zeros((numSamples, 1)))
	
	if kernelType == 'linear':
		kernelValue = matrix_x * sample_x.T
	elif kernelType == 'rbf':
		sigma = kernelOption[1]
		if sigma == 0:
			sigma = 1.0
		for i in xrange(numSamples):
			diff = matrix_x[i, :] - sample_x
			kernelValue[i] = exp(diff * diff.T / (-2.0 * sigma**2))
	else:
		raise NameError('Not support kernel type! You can use linear or rbf!')
	return kernelValue


def calcKernelMatrix(train_x, kernelOption):
	numSamples = train_x.shape[0]
	kernelMatrix = mat(zeros((numSamples, numSamples)))
	for i in xrange(numSamples):
		kernelMatrix[:, i] = calcKernelValue(train_x, train_x[i, :], kernelOption)
	return kernelMatrix


class SVMStruct:
	def __init__(self, dataSet, labels, C, toler, kernelOption):
		self.train_x = dataSet
		self.train_y = labels
		self.C = C
		self.toler = toler
		self.numSamples = dataSet.shape[0]
		self.alphas = mat(zeros((self.numSamples, 1)))
		self.b = 0
		self.errorCache = mat(zeros((self.numSamples, 2)))
		self.kernelOpt = kernelOption
		self.kernelMat = calcKernelMatrix(self.train_x, self.kernelOpt)

		
def calcError(svm, alpha_k):
	output_k = float(multiply(svm.alphas, svm.train_y).T * svm.kernelMat[:, alpha_k] + svm.b)
	error_k = output_k - float(svm.train_y[alpha_k])
	return error_k


def updateError(svm, alpha_k):
	error = calcError(svm, alpha_k)
	svm.errorCache[alpha_k] = [1, error]


def selectAlpha_j(svm, alpha_i, error_i):
	svm.errorCache[alpha_i] = [1, error_i]
	candidateAlphaList = nonzero(svm.errorCache[:, 0].A)[0]
	maxStep = 0; alpha_j = 0; error_j = 0

	if len(candidateAlphaList) > 1:
		for alpha_k in candidateAlphaList:
			if alpha_k == alpha_i: 
				continue
			error_k = calcError(svm, alpha_k)
			if abs(error_k - error_i) > maxStep:
				maxStep = abs(error_k - error_i)
				alpha_j = alpha_k
				error_j = error_k
	else:       	
		alpha_j = alpha_i
		while alpha_j == alpha_i:
			alpha_j = int(random.uniform(0, svm.numSamples))
		error_j = calcError(svm, alpha_j)
	
	return alpha_j, error_j


def innerLoop(svm, alpha_i):
	error_i = calcError(svm, alpha_i)


	if (svm.train_y[alpha_i] * error_i < -svm.toler) and (svm.alphas[alpha_i] < svm.C) or\
		(svm.train_y[alpha_i] * error_i > svm.toler) and (svm.alphas[alpha_i] > 0):

		alpha_j, error_j = selectAlpha_j(svm, alpha_i, error_i)
		alpha_i_old = svm.alphas[alpha_i].copy()
		alpha_j_old = svm.alphas[alpha_j].copy()

		if svm.train_y[alpha_i] != svm.train_y[alpha_j]:
			L = max(0, svm.alphas[alpha_j] - svm.alphas[alpha_i])
			H = min(svm.C, svm.C + svm.alphas[alpha_j] - svm.alphas[alpha_i])
		else:
			L = max(0, svm.alphas[alpha_j] + svm.alphas[alpha_i] - svm.C)
			H = min(svm.C, svm.alphas[alpha_j] + svm.alphas[alpha_i])
		if L == H:
			return 0

		eta = 2.0 * svm.kernelMat[alpha_i, alpha_j] - svm.kernelMat[alpha_i, alpha_i] \
				  - svm.kernelMat[alpha_j, alpha_j]
		if eta >= 0:
			return 0

		svm.alphas[alpha_j] -= svm.train_y[alpha_j] * (error_i - error_j) / eta

		if svm.alphas[alpha_j] > H:
			svm.alphas[alpha_j] = H
		if svm.alphas[alpha_j] < L:
			svm.alphas[alpha_j] = L

		if abs(alpha_j_old - svm.alphas[alpha_j]) < 0.00001:
			updateError(svm, alpha_j)
			return 0

		svm.alphas[alpha_i] += svm.train_y[alpha_i] * svm.train_y[alpha_j] \
								* (alpha_j_old - svm.alphas[alpha_j])

		b1 = svm.b - error_i - svm.train_y[alpha_i] * (svm.alphas[alpha_i] - alpha_i_old) \
													* svm.kernelMat[alpha_i, alpha_i] \
							 - svm.train_y[alpha_j] * (svm.alphas[alpha_j] - alpha_j_old) \
													* svm.kernelMat[alpha_i, alpha_j]
		b2 = svm.b - error_j - svm.train_y[alpha_i] * (svm.alphas[alpha_i] - alpha_i_old) \
													* svm.kernelMat[alpha_i, alpha_j] \
							 - svm.train_y[alpha_j] * (svm.alphas[alpha_j] - alpha_j_old) \
													* svm.kernelMat[alpha_j, alpha_j]
		if (0 < svm.alphas[alpha_i]) and (svm.alphas[alpha_i] < svm.C):
			svm.b = b1
		elif (0 < svm.alphas[alpha_j]) and (svm.alphas[alpha_j] < svm.C):
			svm.b = b2
		else:
			svm.b = (b1 + b2) / 2.0

		updateError(svm, alpha_j)
		updateError(svm, alpha_i)

		return 1
	else:
		return 0


def trainSVM(train_x, train_y, C, toler, maxIter, kernelOption = ('rbf', 1.0)):
	startTime = time.time()

	svm = SVMStruct(mat(train_x), mat(train_y), C, toler, kernelOption)
	
	entireSet = True
	alphaPairsChanged = 0
	iterCount = 0
	while (iterCount < maxIter) and ((alphaPairsChanged > 0) or entireSet):
		alphaPairsChanged = 0

		if entireSet:
			for i in xrange(svm.numSamples):
				alphaPairsChanged += innerLoop(svm, i)
			print '---iter:%d entire set, alpha pairs changed:%d' % (iterCount, alphaPairsChanged)
			iterCount += 1
		else:
			nonBoundAlphasList = nonzero((svm.alphas.A > 0) * (svm.alphas.A < svm.C))[0]
			for i in nonBoundAlphasList:
				alphaPairsChanged += innerLoop(svm, i)
			print '---iter:%d non boundary, alpha pairs changed:%d' % (iterCount, alphaPairsChanged)
			iterCount += 1

		if entireSet:
			entireSet = False
		elif alphaPairsChanged == 0:
			entireSet = True

	print 'Congratulations, training complete! Took %fs!' % (time.time() - startTime)
	return svm


def testSVM(svm, test_x, test_y):
	test_x = mat(test_x)
	test_y = mat(test_y)
	numTestSamples = test_x.shape[0]
	supportVectorsIndex = nonzero(svm.alphas.A > 0)[0]
	supportVectors 		= svm.train_x[supportVectorsIndex]
	supportVectorLabels = svm.train_y[supportVectorsIndex]
	supportVectorAlphas = svm.alphas[supportVectorsIndex]
	matchCount = 0
	for i in xrange(numTestSamples):
		kernelValue = calcKernelValue(supportVectors, test_x[i, :], svm.kernelOpt)
		predict = kernelValue.T * multiply(supportVectorLabels, supportVectorAlphas) + svm.b
		if sign(predict) == sign(test_y[i]):
			matchCount += 1
	accuracy = float(matchCount) / numTestSamples
	return accuracy


def showSVM(svm):
	if svm.train_x.shape[1] != 2:
		print "Sorry! I can not draw because the dimension of your data is not 2!"
		return 1

	for i in xrange(svm.numSamples):
		if svm.train_y[i] == -1:
			plt.plot(svm.train_x[i, 0], svm.train_x[i, 1], 'or')
		elif svm.train_y[i] == 1:
			plt.plot(svm.train_x[i, 0], svm.train_x[i, 1], 'ob')

	supportVectorsIndex = nonzero(svm.alphas.A > 0)[0]
	for i in supportVectorsIndex:
		plt.plot(svm.train_x[i, 0], svm.train_x[i, 1], 'oy')
	
	w = zeros((2, 1))
	for i in supportVectorsIndex:
		w += multiply(svm.alphas[i] * svm.train_y[i], svm.train_x[i, :].T) 
	min_x = min(svm.train_x[:, 0])[0, 0]
	max_x = max(svm.train_x[:, 0])[0, 0]
	y_min_x = float(-svm.b - w[0] * min_x) / w[1]
	y_max_x = float(-svm.b - w[0] * max_x) / w[1]
	plt.plot([min_x, max_x], [y_min_x, y_max_x], '-g')
	plt.show()
