def loc(s):
    for i in range(0, n):
        if per[i][0] == s:
            idx = i
            break

    return idx

n = input()

per = []
for i in range(0, n):
    name = raw_input()
    per.append([name, 0])

for i in range(0, n):
    name = raw_input()
    m, num = [int(t) for t in raw_input().split()]
    idx = loc(name)
    per[idx][1] = per[idx][1] - m
    if num != 0:
        per[idx][1] = per[idx][1] + m % num
    for j in range(0, num):
        temp = raw_input()
        tidx = loc(temp)
        per[tidx][1] = per[tidx][1] + m / num

for i in range(0, n):
    print per[i][0], per[i][1]

