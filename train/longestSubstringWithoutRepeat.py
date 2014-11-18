class Solution:
    def longestPalindrome(self, s):
        length = len(s)
        if length is 1:
            return 1
        str1=""
        for ch in s:
            str1 += ch+"$"
        str1 = str1[:-1]
        
        l=len(str1)
        print str1, l
        result = 0
        for i in range(0, l):
            a=i
            b=i
            count = 0
            while a>=0 and b<l:
                if str1[a] is str1[b]:
                    a -= 1
                    b += 1
                    count += 1
                else:
                    break
            if count > result:
                result = count
        return result
    
    def longestPalindrome1(self, s):
        length = len(s)
        if length is 1:
            return s
        str1="$#"
        for ch in s:
            str1 += ch+"#"
        str1  = str1 +"^"
        
        l=len(str1)
        print l
        result = [0 for t in range(0, l)]

        mx = 0
        idm = 0
        for i in range(1, l-1):
            if mx > i:
                result[i] = min(result[2*idm -i], mx-i)
            else:
                result[i] = 1
            
            while str1[i+result[i]] == str1[i-result[i]]:
                result[i] += 1
            
            if i+result[i] > mx:
                mx = i+result[i]
                idm = i
        print result
        num = max(result)-1
        print '---' 
        ind = result.index(max(result))
        print ind, num
        if ind-1-num < 0:
            start = 0
        else:
            start = (ind-1-num)/2
        print '---' 
        print start, num
        return s[start:start + num]


if __name__ == "__main__":
    sol = Solution()
    s=""
    print sol.longestPalindrome1(s)
