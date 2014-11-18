class Solution:
    def isPalindrome(self, s):
        if s=='':
            return True
        else:
            i=0
            size = len(s)-1
            while i < size :
                if not s[i].isalpha():
                    i+=1
                elif not s[size].isalpha():
                    size-=1
                elif s[i].upper()==s[size].upper():
                    i+=1
                    size-=1
                else:
                    return False
            if (i==size and s[i] == s[size]) or i-size==1 :
                return True
    def minimumTotal(self, triangle):
        totalLayer = len(triangle)
        print totalLayer
        layer = 1
        while layer<=totalLayer-1:
            for index in range(0, layer+1):
                a = index
                if index-1<0:
                    a1=999999
                else:
                    a1 = triangle[layer-1][index-1]

                if index>layer-1:
                    b1=999999
                else:
                    b1 = triangle[layer-1][index]

                if a1>b1:
                    triangle[layer][a] += b1
                else:
                    triangle[layer][a] += a1
                
            layer += 1 
        print triangle[totalLayer-1] 
        return min(triangle[totalLayer-1])

if __name__=='__main__':

    sol = Solution()
    res = sol.isPalindrome('aa')
    res2 = sol.minimumTotal()
    print res2
