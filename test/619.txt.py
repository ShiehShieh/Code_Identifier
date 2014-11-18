def gcd(x, y):
	if(y == 0):
		return x
	return gcd(y, x % y)

s = input().split(' ')
a = int(s[0])
b = int(s[1])
print(a * b // gcd(a, b))
