def FUN(s) :
    a = []
    a.append( int(s[0]) )
    for i in range(1,len(s)) :
        a.append( a[i-1] ^ int(s[i]) )
    ret = 0
    for i in range(len(s)) :
        ret = ret * 2 + a[i]
    return ret

a = raw_input()
b = raw_input()
print abs(FUN(a) - FUN(b))
