x = raw_input().split()
a = int(x[0])
b = int(x[1])
c = a * b

while b != 0:
    t = a
    a = b
    b = t % b

print(c /a)