
def gcd(a, b):
	if(a == 0):
		return b
	else:
		return gcd(b % a, a)

s = raw_input()
a = int(s.split()[0])
b = int(s.split()[1])

print(str(a * b / gcd(a, b)))