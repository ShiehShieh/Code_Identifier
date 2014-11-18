class Solution:
	def backtrack(self, index, s, dict, flag):
		temp=""
		if index>=len(s):
			print flag
			if flag == 1:
				return True
			else:
				return False
		
		for i in range(index, len(s)):
			temp += s[i]
			print temp
			flag = 0
			if temp in dict:
				flag = 1
				print 'find'
				if self.backtrack(i+1, s, dict, flag):
					return True
				
		'''
		print flag
		if flag==1:
			return True
		else:
			return False
		'''		
		return False	
			
		
	def wordBreak(self, s, dict):
		flag = 0
		return self.backtrack(0, s, dict, flag)


if __name__=="__main__":
	sol = Solution()
	a=""
	set1=set([])
	print sol.wordBreak(a, set1)

		
	
