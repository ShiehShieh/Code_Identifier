import math
p, q = [float(x) for x in raw_input().split()]

num = 1

while 1 :
    if int(math.ceil(num * p / 100)) == int(math.floor(num * q / 100)):
        break
    num = num + 1

print num