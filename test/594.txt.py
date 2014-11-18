def pow(a, b, MOD):
	if b == 0:
		return 1
	elif b == 1:
		return a % MOD
	t = pow(a, int(b/2), MOD)
	if b%2 == 0:
		return (t*t) % MOD
	else:
		return (t*t*a) % MOD

N, M, K, X = raw_input().split()
n, m, k, x = int(N), int(M), int(K), int(X)
    
print (m*pow(10, k, n)+x)%n