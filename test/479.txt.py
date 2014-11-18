s = raw_input()
s = s.strip().split(' ')
l = int(s[0])
r = int(s[1])
sum = 0
for i in range(l,r+1):
	n = str(i)
	sum += n.count('2')
print sum