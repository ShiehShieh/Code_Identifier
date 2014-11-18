a,b= raw_input().split(' ')
a=int(a)
b=int(b)
def gcd(a,b):
        tmp=max(a,b)%min(a,b)
        if tmp==0:
                return min(a,b)
        else:
                return gcd(min(a,b),tmp)
gong=a*b/gcd(a,b)
print gong  