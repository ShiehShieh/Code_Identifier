def FUN(l , a) :
    u = 0
    p = 0
    x = [0 for i in range(0,l+1)]
    for i in range(0,l) :
        if p == 0 :
            if a[i] == '1' :
                u = 1
                p = 1
                x[l-i] = 1
        elif p == -2 :
            if a[i] == '1' :
                p = 1
                x[l-i] -= u
                u = -u
        elif p == 2 :
            if a[i] == '0' :
                p = -1
                x[l-i] -= u
                u = -u
        elif p == -1 :
            if a[i] == '0' :
                p = -2
            else :
                p = 1
                x[l-i] -= u
                u = -u
        elif p == 1 :
            if a[i] == '1' :
                p = 2
            else :
                p = -1
                x[l-i] += u
    return x

a = raw_input()
b = raw_input()
l = len(a)
f = []
f.append(0)
f.append(1)
f.append(2)
for i in range(3,l+1) :
    f.append( f[i-1] + f[i-2]*2 + 1 )

x = FUN(l , a)
y = FUN(l , b)

ans = 0
for i in range(1,l+1) :
    ans += f[i] * x[i]
for i in range(1,l+1) :
    ans -= f[i] * y[i]
ans = abs(ans)
print ans

'''
00001
00011
00010
00110
00111
00101
00100
01100
01101
01111
01110
01010
01011
01001
01000
11000
11001
11011
11010
11110
11111 ... 21
11101
11100
10100
10101 ... ac
10111
10110
10010
10011
10001
10000 ... 10
'''
