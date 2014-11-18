a,b,k,n,m = [int(x) for x in raw_input().split()]
MOD = 10007
def C(x,y):
    ret = 1
    fucky = 1
    for i in range(x-y+1,x+1):ret*=i
    for i in range(1,y+1):fucky*=i
    return ret/fucky
ans = pow(a,n)*pow(b,m);
ans *= C(k,n)
print ans%MOD
