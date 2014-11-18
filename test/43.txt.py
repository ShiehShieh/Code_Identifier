n = input()

data = []
sch = [0 for x in range(0, n)]
for i in range(0, n):
    data.append([t for t in raw_input().split()])


for i in range(0, n):
    if int(data[i][1]) > 80 and int(data[i][5]) > 0:
        sch[i] = sch[i] + 8000
    if int(data[i][1]) > 85 and int(data[i][2]) > 80:
        sch[i] = sch[i] + 4000
    if int(data[i][1]) > 90:
        sch[i] = sch[i] + 2000
    if int(data[i][1]) > 85 and data[i][4] == "Y":
        sch[i] = sch[i] + 1000
    if int(data[i][2]) > 80 and data[i][3] == "Y":
        sch[i] = sch[i] + 850

maxmum = 0
idx = 0
for i in range(0, n):
    if sch[i] > maxmum:
        idx = i
        maxmum = sch[i]

print data[idx][0]
print sch[idx]
print sum(sch)
