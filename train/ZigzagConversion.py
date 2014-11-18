
class Solution:
    def convert(self, s, nRows):
        print s
        l = len(s)
        if l <= nRows or nRows == 1:
            return s
        steps = 2*nRows - 2
        
        result=""
        for i in range(0, nRows):
            j = 0
            while (i + steps*j)<l:
                temp1 = s[i + steps*j]
                if i>0 and i<nRows-1 and steps*j + nRows - 1 + nRows - 1 - i <l:
                    temp2 = s[ steps*j + nRows - 1 + nRows - 1 - i] 
                    result += temp1+temp2
                else:
                    result += temp1
                j += 1
      
        return result               
    
if __name__ == '__main__':
    sol = Solution()
    print sol.convert("", 3)
    pass
