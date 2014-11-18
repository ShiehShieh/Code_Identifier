k = 1
s = 0
for i in range(1, 8):
    a, b = raw_input().split()
    a = int(a)
    b = int(b)
    if s<a+b:
        s = a+b
        k = i
    #print(s)

print(k)



