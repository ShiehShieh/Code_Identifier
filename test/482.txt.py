line = raw_input()
apple = [int(f) for f in line.split()]
h = int(input()) + 30
res = 0
for i in apple:
    if(h>=i):
        res = res + 1
print(res)
