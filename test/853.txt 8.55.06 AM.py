class Expression:
    def __init__(self, op, l, r):
        self.op = op
        self.left = l
        self.right = r

    def getResult(self, v):
        if self.op=='NULL':
            if self.left == 'a':
                return v
            else:
                return self.left
        
        if self.left == 'a':
            l = v
        else:
            l = self.left.getResult(v)
            
        if self.right == 'a':
            r = v
        else:
            r = self.left.getResult(v)

        if self.op == '+':
            return l + r
        elif self.op =='-':
            return l - r
        elif self.op =='*':
            return l * r
        elif self.op =='^':
            return l ^ r
        
        return 0;

    def compare(self, e):
        for i in range(0, 20):
            if self.getResult(i) != e.getResult(i):
                return False
        return True
    
def Parser(s):
    #print (s)
    high_op = ''
    high_pos = ''
    left, s = FindUnit(s)
    while True:
        if s=='':
            return left
        if s[0]=='+' or s[0]=='-':
            return Expression(s[0], left, Parser(s[1:]))
        if s[0]=='^':
            right, s = FindUnit(s[1:])
            left = Expression('^', left, right)
            continue
        right, s = FindUnit(s[1:])
        while (s!='' and s[0]=='^'):
            rright, s = FindUnit(s[1:])
            right = Expression(s[0], right, rright)
        left = Expression('*', left, right)
        

def FindUnit(s):

    if s[0]=='+':
        return FindUnit(s[1:])
    if s[0]=='-':
        a , b = FindUnit(s[1:])
        return Expression('-', Expression('NULL', 0, 0), a), b
    if s[0]=='(':
        j = 1
        lc = 1
        while lc > 0:
            if s[j]=='(':
                lc += 1
            elif s[j]==')':
                lc -= 1
            j += 1
        return Parser(s[1:j-1]), s[j:]
    if s[0]=='a':
        return Expression('NULL', 'a', 0), s[1:]
    if s[0].isdigit():
        j = 1
        l = len(s)
        while j < l and s[j].isdigit():
            j += 1
        return Expression('NULL', int(s[:j]), 0), s[j:]

    
import sys
target = Parser(''.join(sys.stdin.readline().strip('\n').split(' ')))
n = int(sys.stdin.readline())
ans = ""
for i in range(0, n):
    if target.compare(Parser(''.join(sys.stdin.readline().strip('\n').split(' ')))):
        ans += chr(i+ord('A'))
    
print (ans)
