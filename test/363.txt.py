s=map(int,raw_input().split(' '))
a=s[0]
b=s[1]
c=a%b
d=a*b;
while c!=0L:
    a=b
    b=c
    c=a%b
print d/b