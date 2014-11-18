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
        
        l = self.left.getResult(v)
        r = self.right.getResult(v)

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
            v = e.getResult(i)
            #print(v)
            if self.getResult(i) != e.getResult(i):
                return False
        return True

    def toString(self):
        if self.op=='NULL':
            return str(self.left)
        else:
            return "("+self.left.toString()+self.op+self.right.toString()+")"
        return "";
    
def Parser(s):
    #print (s)
    high_op = ''
    high_pos = ''
    left, s = FindUnit(s, 0)
    while True:
        if s=='':
            return left
        op = s[0]
        right, s = FindUnit(s[1:], 0)
        left = Expression(op, left, right)

def FindUnit(s, Level):

    if s[0]=='+':
        return FindUnit(s[1:], Level)
    if s[0]=='-':
        a , b = FindUnit(s[1:], Level)
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
        left = Parser(s[1:j-1])
        s = s[j:]
        while True:
            if s=='' or getLevel(s[0]) <= Level:
                return left, s
            op = s[0]
            right, s = FindUnit(s[1:], Level+1)
            left = Expression(op, left, right)
        
    if s[0]=='a':
        left = Expression('NULL', 'a', 0)
        s = s[1:]
        while True:
            if s=='' or getLevel(s[0]) <= Level:
                return left, s
            op = s[0]
            right, s = FindUnit(s[1:], Level+1)
            left = Expression(op, left, right)
    if s[0].isdigit():
        j = 1
        l = len(s)
        while j < l and s[j].isdigit():
            j += 1
        left = Expression('NULL', int(s[:j]), 0)
        s = s[j:]
        while True:
            if s=='' or getLevel(s[0]) <= Level:
                return left, s
            op = s[0]
            right, s = FindUnit(s[1:], Level+1)
            left = Expression(op, left, right)

def getLevel(c):
    if c=='+' or c=='-':
        return 0
    if c=='*':
        return 1
    if c=='^':
        return 2
    
import sys
target = Parser(''.join(sys.stdin.readline().strip('\n').split(' ')))
#print(target.toString())
n = int(sys.stdin.readline())
ans = ""
for i in range(0, n):
    e = Parser(''.join(sys.stdin.readline().strip('\n').split(' ')))
    #print (e.toString())
    if target.compare(e):
        ans += chr(i+ord('A'))
    
print (ans)
