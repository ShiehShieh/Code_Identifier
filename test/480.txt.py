s = raw_input()
s = s.strip().split(' ')
n = int(s[0])
x = s[1]
sum = 0
for i in xrange(1,n+1):
	t = str(i)
	sum += t.count(x)
print sum