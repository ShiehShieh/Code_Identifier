n = input()
x = 1
ans = 1
for i in range(n,2,-1) :
    x *= (-i)
    ans += x
if ans < 0 : ans *= -1
print ans
