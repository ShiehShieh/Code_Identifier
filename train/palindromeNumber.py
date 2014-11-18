class Solution:
    def isPalindrome(self, x):
        if x<0:
            return False
        elif x<10 and x>=0:
            return True
            
        temp = x
        index = 10
        
        while x/(10**index) is 0:
            index -= 1
            
        i = 0
        result = 0
        while index >= 0:
            val = (x/(10**index))*(10**i)
            x -=  (x/(10**index))*(10**index)
            result += val
            i += 1
            index -= 1
        
        a=None
        if temp == result:
            a = True
        else:
            a = False

        return a

if __name__ == '__main__':
    sol = Solution()
    print sol.isPalindrome(313)
    pass
