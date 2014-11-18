def exgcd(a,b):
    global x, y
    if(b==0):
        x=1
        y=0
    else:
        exgcd(b,a%b)
        t=x
        x=y
        y=t-a//b*y
a,b=[int(i) for i in raw_input().split()]
exgcd(a,b)
print (x+b)%b
