'''
Created on Oct 13, 2013

@author: LMY
'''
def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)


a,b = raw_input().split(' ')
a = int(a);
b = int(b);
print int(a*b)
          
          
          
          
          
          
          