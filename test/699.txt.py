a=input()
b=input()
a=float(a)
b=float(b)
a/=100
b/=100
x=1
while(abs(int(x*a-0.00000001)-int(x*b+0.00000001))!=1):
    x+=1
print x