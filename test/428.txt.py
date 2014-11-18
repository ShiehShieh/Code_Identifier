n = input()
u = 2
while n >= u :
    n -= u
    u += 1
v = u - n
s = ''
ans = 1
for i in range(2,v) :
    s = s + str(i) + ' '
    ans *= i
for i in range(v+1,u+1) :
    s = s + str(i) + ' '
    ans *= i
print s
print ans
