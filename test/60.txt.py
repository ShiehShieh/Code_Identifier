apple = [int(x) for x in raw_input().split()]
h = input()
num = 0

for i in range(0, 10):
    if h + 30 >= apple[i]:
        num = num + 1

print num