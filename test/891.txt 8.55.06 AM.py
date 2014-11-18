n = int(raw_input())
name_max = ''
money_sum = 0
money_max = 0
for i in xrange(n):
	name, qm, py, gb, xb, lw = raw_input().split(' ')
	qm, py, lw = int(qm), int(py), int(lw)
	money = 0
	if lw >= 1 and qm > 80:
		money += 8000
	if qm > 85 and py > 80:
		money += 4000
	if qm > 90:
		money += 2000
	if qm > 85 and xb == 'Y':
		money += 1000
	if py > 80 and gb == 'Y':
		money += 850

	money_sum += money
	if money > money_max:
		money_max = money
		name_max = name

print name
print money
print money_max