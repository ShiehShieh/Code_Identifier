import random

alpha = input().strip()
alpha = alpha.replace('^', '**')
n = int(input())
check_exps = []
for x in range(0, n):
    line = input().strip()
    line = line.replace('^', '**')
    check_exps.append(line)
    pass

check_times = 100
max_num = 10000
match = {}
for x in range(0, check_times):
    in_num = random.randint(0, max_num)
    out_num = eval(alpha.replace('a', str(in_num)))
    match[in_num] = out_num
    pass

equal_exps = []
for x in range(0, n):
    same = True
    for (key, value) in match.items():
        if eval(check_exps[x].replace('a', str(key))) != value:
            same = False
            break
        pass
    if same:
        equal_exps.append(chr(ord('A') + x))
    pass
print(''.join(equal_exps))