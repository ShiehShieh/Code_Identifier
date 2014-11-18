a = raw_input()
b = raw_input()
l = len(a)
f = []
f.append(0)
f.append(1)
f.append(2)
for i in range(3,l+2) :
    f.append( f[i-1] + f[i-2]*2 + 1 )
c = f[l+1]
p = 1
x = [0 for i in range(0,l+1)]
for i in range(0,l) :
    if p == 1 :
        if a[i] == '1' :
            x[l-i] += 1
            p = 2
    else :
        if a[i] == '0' :
            x[l-i] += 1
            p = 1
d = f[l+1]
p = 1
y = [0 for i in range(0,l+1)]
for i in range(0,l) :
    if p == 1 :
        if b[i] == '1' :
            y[l-i] += 1
            p = 2
    else :
        if b[i] == '0' :
            y[l-i] += 1
            p = 1
ans = 0
for i in range(1,l+1) :
    ans += f[i] * x[i]
for i in range(1,l+1) :
    ans -= f[i] * y[i]
ans = abs(ans)
print ans
