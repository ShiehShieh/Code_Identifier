a,b=raw_input().split(' ')
a=int(a)
b=int(b)
if a<b:
    a,b=b,a
m=a
n=b
while 1:
    r=m%n
    m=n
    n=r
    if r==0:
        break
mi=(a*b)//m
print mi