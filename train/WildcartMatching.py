class Solution:

    def isMatch(self, s, p):
		if len(p) == 0:
			return len(s) == 0
		if s=="" and p[0]=="*":
			return True
		if s=="" and p[0] !="*":
			return False
		
		j = 0
		res = [False for i in range(0, len(s)+1)]
		res[0] = True
		for i in range(0, len(p)):
			if p[i] == "*":
				j=0
				while j<=len(s) and res[j]==False:
					j += 1
				while j<=len(s):
					res[j] = True
					j += 1

						
			else:
				for j in range(len(s)-1, -1, -1):
					print j
					if p[i]=="?" or p[i]==s[j]:
						res[j+1] = res[j]
					
			if p[i] == "*" :		
				res[0] = res[0]
			else:
				res[0] = False
		return res[len(s)]
				
					

if __name__== "__main__":
	sol = Solution()
	print sol.isMatch("cabab", "*ab")
