a,b=raw_input().split(' ')
a=float(a)
b=float(b)
a/=100
b/=100
x=1
while(int(x*b-0.000001)-int(x*a+0.000001)<1):
    x+=1
print x