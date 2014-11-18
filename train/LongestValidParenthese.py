class Solution:
	def longestValidParentheses(self, s):
		pStack=[]
		idxStack=[]
		res=0
		last1 = -1
		for i in range(0, len(s)):
			if s[i] == "(":
				pStack.append(s[i])
				idxStack.append(i)
				print pStack
			elif s[i] == ")":
				if len(pStack) == 0:
					last1 = i
				
				elif len(pStack) != 0:
					p = pStack.pop()
					idxStack.pop()
					#idx = len(pStack)
					if len(pStack)==0:
						print '0'
						res = max(res, i-last1)
					else:
						res = max(res, i-idxStack[-1])
					print 'n;', res

							
						
		return res

if __name__=="__main__":
	sol = Solution()

	print sol.longestValidParentheses("())")