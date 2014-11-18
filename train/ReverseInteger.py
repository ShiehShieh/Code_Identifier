
class Solution:
    def reverse(self, x):
        if x is 0:
            return x
        flag = 0
        if x<0:
            num = 0-x
            flag = 1
        else:
            num = x
        
        i = 18
        j=0
        result=0
        while num/(10**i) == 0:
            i -= 1
        while i>=0:
            result += (num/(10**i))*(10**j)
            num -= (num/(10**i))*(10**i)
            j += 1
            i -= 1
        
        if flag is 1:
            result = 0-result
        
        return result
            
if __name__ == '__main__':
    sol = Solution()
    print sol.reverse(0)
    pass
