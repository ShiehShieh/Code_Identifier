class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
	def merge(self, intervals):
		if len(intervals)<=1:
			return intervals
		
		intervals = sorted(intervals, key=lambda intl: intl.start)
		res=[]
		res.append(intervals[0])
		for i in range(1, len(intervals)):
			cur = intervals[i]
			prev = res[-1]
			if prev.end>=cur.start and prev.end<=cur.end:
				res[-1].end = cur.end

			elif prev.end<cur.start:
				res.append(cur)
				
		return res
        
		
if __name__=="__main__":
	sol = Solution()
	i1 = Interval(1,4)
	i2 = Interval(0,4)
	res = sol.merge([i1, i2])
	for i in res:
		print i.start, i.end
		
