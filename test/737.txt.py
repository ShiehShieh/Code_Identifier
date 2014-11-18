import sys
import random

def eq(ans,f):

	for i in xrange(5):
		a=random.randint(0,100)
		
		if eval(ans)!=eval(f):
			return False

	return True

def pre(s):
	s=s.replace('^','**')
	s=s.strip()
	return s

sys.stdin=open('test.in','r')

s=raw_input()
s=pre(s)

n=int(raw_input())

t=sys.stdin.readlines()

for i,item in enumerate(t):
	t[i]=pre(item)

ans=[]

for i in range(len(t)):
	if eq(s,t[i]):
		ans.append(chr(ord('A')+i))

print ''.join(ans)
