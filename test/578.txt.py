n = input()
Dict = {}
Sort = {}
for i in range(0,n):
    name = raw_input()
    Dict[name] = 0
    Sort[i] = name

for i in range(0,n):
    name = raw_input()
    tmp = raw_input()
    tmp2 = tmp.split(' ')
    money = int(tmp2[0])
    people = int(tmp2[1])
    if(people == 0):
        continue
    tmp3 = money - money%people
    Dict[name] += -tmp3
    for i in range(0,people):
        kname = raw_input()
        Dict[kname] += (money - money%people)/people

for i in range(0,n):
    print Sort[i],Dict[Sort[i]]
