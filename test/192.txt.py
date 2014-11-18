def gcd(x,y):
	if not y:
		return x
	else:
		return gcd(y,x%y)

def lcm(x,y):
	return x/gcd(x,y)*y

a,b=map(int,raw_input().split(' '))

print lcm(a,b)
