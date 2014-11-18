'''
Created on Sep 22, 2014

@author: yqian33
'''
class Solution:
    # @return an integer
    def atoi(self, str):
        MAX_INT = 2147483647
        MIN_INT = -2147483648
        
        if str is None or str is "":
            return 0
        str = str.strip()
        i=0
        l = len(str)
        while str[i] is ' ':
            i += 1
        print i
        if str[i].isalpha():
            print 'here'
            return 0
        result=0
        j=l-1
        add=0
        flag = 1
        while j>=i:
            #print str[j]
            if str[j] is '-':
                flag = 0
                if j > i:
                    return 0
            elif str[j] is '+':
                flag = 1
                if j> i:
                    return 0
            elif not str[j].isdigit():
                add = 0
                result = 0 
            elif str[j] is not ' ':
                result += (ord(str[j])-48)*(10**add)
                print result
                
                #print result
                add += 1

            j -= 1
            
        if result > MAX_INT and str[i] is not '-':
            return MAX_INT
        elif result > MAX_INT+1 and str[i] is '-':
            return MIN_INT
        
        if not flag:
            result = 0 - result
        print 'a:', result   
        return result
        
if __name__ == '__main__':
    sol = Solution()
    print sol.atoi("")
    print 'pass'
    pass