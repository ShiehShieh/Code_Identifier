# calculate the greatest common divisor
def gcd(first, second):
	if (first < second):
		first, second = second, first
	while second != 0:
		first, second = second, first % second
	return first

# calculate the least common multiple
def lcm(first, second):
	gcd_num = gcd(first, second)
	return first * second / gcd_num

a, b = raw_input().split(' ')
print lcm(int(a),int(b))