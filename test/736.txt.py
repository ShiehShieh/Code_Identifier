import sys
a , b = map(int,sys.stdin.readline().split())
aa = a
bb = b
if a < b:
    t = a
    a = b
    b = t
c = a % b
while c!=0:
    c = a % b
    a = b
    b = c
d = (aa * bb)/a
print d;