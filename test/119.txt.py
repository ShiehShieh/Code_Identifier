def gcd(m, n):
	if m < n:
		m, n = n, m
	while (m % n != 0):
		m %= n
		m ,n = n, m
	return n

def lcm(m, n):
	return m * n / gcd(m , n)

s = raw_input()
a, b = [int(x) for x in s.split(' ')]
print lcm(a, b)
