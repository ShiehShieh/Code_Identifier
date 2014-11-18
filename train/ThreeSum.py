class Solution:
	def backtrack(self, tmp, res, idx, num):
		if len(tmp)==3 and sum(tmp)==0:
			cur = sorted(tmp)
			if cur not in res:
				print 'add', cur, res
				res.append(cur)
			return
		else:
			for i in range(idx, len(num)-1):
				tmp.append(num[idx])
				self.backtrack(tmp, res, i+1, num)
				tmp.pop()
			return res
					
	def threeSum(self, num):
		if len(num)<3:
			return []
		else:
			res=[]
			tmp=[]
			return self.backtrack(tmp, res, 0, num)

if __name__ == "__main__":
	sol = Solution()
	num=[-2,-2,0,-5,-1,-3,0,4,3,4,1,3,0,-1,0,3]
	print sol.threeSum(num)


		
	