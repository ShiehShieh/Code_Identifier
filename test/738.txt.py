def is_yuanshi(arr):
	return (int(arr[1]) > 80 and int(arr[5]) >= 1)

def is_wusi(arr):
	return (int(arr[1]) > 85 and int(arr[2]) > 80)

def is_youxiu(arr):
	return int(arr[1]) > 90

def is_xibu(arr):
	return (int(arr[1]) > 85 and arr[4] == 'Y')

def is_gongxian(arr):
	return (int(arr[2]) > 80 and arr[3] == 'Y')

num_students = input()
students = []
scores = {}
for i in xrange(0, num_students):
	line = raw_input()
	input_arr = line.split(' ')
	students.append(input_arr)
for arr in students:
	score = 0
	if is_yuanshi(arr): score += 8000
	if is_wusi(arr): score += 4000
	if is_youxiu(arr): score += 2000 
	if is_xibu(arr): score += 1000 
	if is_gongxian(arr): score += 850 
	scores[arr[0]] = score
mostMoney = max(scores.values())
mostMoneyStu = [name for name, money in scores.iteritems() if money == mostMoney]
totalMoney = sum(scores.values())

print mostMoneyStu[0]
print mostMoney
print totalMoney