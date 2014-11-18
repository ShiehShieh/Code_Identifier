
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution:
    def maxPoints(self, points):
        
        sizel = len(points)
        if sizel<=2:
            return sizel
        
        dict2 = {}
        for i in range(0, sizel):
            key=(points[i].x ,points[i].y)
            if key in dict2:
                dict2[key] += 1
            else:
                dict2[key] = 1
        print len(dict2)
        
        size = len(dict2)
        if size<=2:
            return sizel
           
        p = dict2.keys()
        i=0
        num=0
        for i in range (0, size-1):
            dict1={}
            for j in range(i+1, size):
                if p[j][0]-p[i][0] == 0:
                    rate=str(p[i][0])
                else:
                    rate = (float)(p[j][1]-p[i][1])/(float)(p[j][0]-p[i][0])
                if rate in dict1:
                    if p[i] not in dict1[rate]: 
                        dict1[rate].append(p[i])
                    if p[j] not in dict1[rate]:
                        dict1[rate].append(p[j])
                else:
                    nl=[p[i],p[j]]
                    dict1[rate] = nl
            print p[i][0], p[i][1], dict1
            numlist=[]
            for (k,v) in dict1.items():
				c=0
				for kk in v:
					c += dict2[kk]
				numlist.append(c)

            newnl = sorted(numlist, reverse=True)
            print newnl[0]
            if num<newnl[0]:
				num = newnl[0]	

        return num
        

if __name__ =='__main__':
	p = Point(0,0)
	p1 = Point(1,1)
	p2 = Point(1,-1)
	l=[]
	l.append(p)
	l.append(p1)
	l.append(p2)
	sol = Solution()
	print sol.maxPoints(l)
