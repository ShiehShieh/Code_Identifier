class Solution:
	def rotate(self, matrix):
		row = len(matrix)
		for i in range(0, row):
			for j in range(i+1, row):
				matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		col = len(matrix[0])
		for j in range(0, col):
			i = 0
			k = row -1
			while i<k:
				matrix[i][j], matrix[k][j] = matrix[k][j], matrix[i][j]
				i += 1
				k -= 1

		return matrix
	def printM(self, matrix):
		for item in matrix:
			print item
			
		
	def spiralOrder(self, matrix):
		res=[]
		n = len(matrix)
		c=0
		if n%2==0:
			c=n/2
		else:
			c=n/2+1
		idx = 0
		for i in range(0, c):
			s=0
			for j in range(0, n):
				res.append(matrix[idx][j])

				
				
			
			
		

if __name__=="__main__":
	sol = Solution()
	sol.spiralOrder([ [1,2,3,4,5], [6,7,8,9,10], [11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]])
			
