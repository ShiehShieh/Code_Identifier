class Solution:
    # @return a boolean
    def isValid(self, s):
		st=[]
		for ch in s:
			if ch == "{" or ch == "(" or ch =="[":
				st.append(ch)
			else:
				if len(st)==0:
					return False
				elif ch == "}":
					temp = st.pop()
					if temp != "{":
						return False
				elif ch == "]":
					temp = st.pop()
					if temp != "[":
						return False
				elif ch == ")":
					temp = st.pop()
					if temp != "(":
						return False
		if len(st) != 0:
			return False
		return True		

if __name__=='__main__':
	sol = Solution()
	print sol.isValid("{([])}")
	print sol.isValid("{([()][()])}")