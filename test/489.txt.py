a,b= raw_input().split(' ')
a=int(a)
b=int(b)
def divisor(a,b):
        tmp=max(a,b)%min(a,b)
        if tmp==0:
                return min(a,b)
        else:
                return divisor(min(a,b),tmp)
gong=a*b/divisor(a,b)
print gong            
            