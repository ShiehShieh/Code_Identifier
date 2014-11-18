def is_yuanshi(l):
	return (int(l[1]) > 80 and int(l[5]) >= 1)
def is_wusi(l):
	return (int(l[1]) > 85 and int(l[2]) > 80)
def is_youxiu(l):
	return (int(l[1]) > 90)
def is_xibu(l):
	return (int(l[1]) > 85 and l[4] == 'Y')
def is_banji(l):
	return (int(l[2]) > 80 and l[3] == 'Y')

stu_count = input()
names = {}
for i in xrange(stu_count):
	l = raw_input().split(' ')
	money = 0
	money += 8000 if(is_yuanshi(l)) else 0
	money += 4000 if(is_wusi(l)) else 0
	money += 2000 if(is_youxiu(l)) else 0
	money += 1000 if(is_xibu(l)) else 0
	money += 850 if(is_banji(l)) else 0
	names[l[0]] = money
most_money = max(names.values())
print [key for key, value in names.items() if value == most_money][0]
print most_money
print sum(names.values())