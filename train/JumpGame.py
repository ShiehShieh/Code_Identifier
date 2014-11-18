class Solution:
	def helper(self, A, idx):
		if idx == len(A)-1:
			return True
		
		for i in range(1, A[idx]+1):
			if self.helper(A, idx+i):
				return True
		return False	
		
	def canJump1(self, A):
		if len(A)==0:
			return False
		else:
			idx = 0
			return self.helper(A, idx)

	def canJump(self, A):
		maxCover = 0
		i = 0
		while i <= maxCover and i<len(A):
			print i, maxCover
			if A[i]+i>maxCover:
				maxCover = A[i] + i
			if maxCover>=len(A)-1:
				return True
			i += 1
		return False
			
			
			
			
			

if __name__=='__main__':
	sol = Solution()
	s=[2,3,1,1,4]
	print sol.canJump(s)
