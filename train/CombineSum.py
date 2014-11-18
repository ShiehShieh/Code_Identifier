class Solution:
    def help(self, candidates, target, index, res, tmp):
        if target == 0:
            re = tmp[:]
            res.append(re)
            tmp=[]
            return res
        elif (index == len(candidates)) or target<0:
            return res
        else:
            for i in range(index, len(candidates)):
                if i>index and candidates[i] == candidates[i-1]:
					continue;
                
                tmp.append(candidates[i])
                self.help(candidates, target-candidates[i], i+1, res, tmp)
                tmp.pop()
                
    def combinationSum2(self, candidates, target):
        candidates = sorted(candidates)
        if len(candidates) == 0:
            return []
        else:
            res=[]
            tmp=[]
            self.help(candidates, target, 0, res, tmp)
            return res

if __name__=="__main__":
	sol = Solution()
	s=[]
	print sol.combinationSum2(s, 25)
