s = raw_input()
n = len(s)
B = 1
A = 0
for i in range(0,n) :
    c = s[n-i-1]
    if c == 'L' :
        A, B = A, 2*B
    if c == 'R' :
        A, B = A+B, 2*B
    if c == 'P' :
        A, B = A, B
    if c == '*' :
        A, B = 3*A+B, 5*B
print A+B
