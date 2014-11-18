class Solution:
	def subsetsWithDup(self, S):
		S = sorted(S)
		n = len(S)
		if n == 0:
			return []
		else:
			tmp=[]
			res=[[]]
			self.helper(S, 0, tmp, res)
			return res
	def helper(self, s, ind, tmp, res):
		for i in range(ind, len(s)):
			tmp.append(s[i])
			cur = tmp[:]
			res.append(cur)
			self.helper(s, i+1, tmp, res)
			tmp.pop()
			while i<len(s)-1 and s[i]==s[i+1]:
				i += 1
				
				

if __name__=="__main__":
	sol = Solution()
	print sol.subsetsWithDup([1,1])
			
		
		
