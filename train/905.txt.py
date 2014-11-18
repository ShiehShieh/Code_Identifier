import sys
n = int(sys.stdin.readline().strip())
s = {}
for i in range(0, n):
	line = sys.stdin.readline()
	name, s1, s2, c1, c2, c3 = line.strip().split(' ')
	s1 = int(s1)
	s2 = int(s2)
	c3 = int(c3)
	s[name] = 0
	if s1 > 80 and c3 >= 1:
		s[name] += 8000
	if s1 > 85 and s2 > 80:
		s[name] += 4000
	if s1 > 90:
		s[name] += 2000
	if s1 > 85 and c2 == 'Y':
		s[name] += 1000
	if s2 > 80 and c1 == 'Y':
		s[name] += 850
hname = ''
hmoney = 0
for (name, money) in s.items():
	if money > hmoney:
		hmoney = money
		hname = name
print(hname + '\n' + str(hmoney) + '\n' + str(sum(s.values())))