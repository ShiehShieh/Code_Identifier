class Solution:
    def findSubstring(self, S, L):
        print S
        if len(L) == 0 or len(S) == 0:
            return 0
        else:
            res=[]
            l1 = len(L[0])
            l2 = len(L)
            l3 = l1*l2
            print l1, l2, l3
            map1={}
            for item in L:
                if item not in map1:
                    map1[str(item)] = 1
                else:
                    map1[str(item)] +=1
			
				
            for i in range(0, len(S)-l3+1):
                map2={}
                s1 = S[i:i+l3]
                print '--',s1
                count = 0
                for j in range(0, l3, l1):
                    subs = s1[j:j+l1]
                    print j, subs
                    if subs not in map1:
                        break
                    else:
                        if subs not in map2:
                            print 'add to map2'
                            map2[subs] = 1
                            count += 1
                        else:
                            map2[subs] += 1
                            count += 1 
                            if map2[subs]>map1[subs]:
                                count += 1
                                break
                print count
                if count == l2:
                    res.append(i)
        return res

if __name__=="__main__":
	sol = Solution()
	S=""
	L=["a","b"]
	res = sol.findSubstring(S,L)
	print res
	pass
