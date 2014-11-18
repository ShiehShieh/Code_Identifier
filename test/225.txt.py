def gcd(n,m):
	return n if m==0 else gcd(m,n%m)
def lcm(n,m):
	return n*m/gcd(n,m)
n,m=map(int,raw_input().split())
print lcm(n,m)