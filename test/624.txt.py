x=int(raw_input())
y=int(raw_input())
def gcd(x,y):
	if x % y==0:
		return y
	return gcd(y,x % y)
print (x*y/gcd(x,y))
