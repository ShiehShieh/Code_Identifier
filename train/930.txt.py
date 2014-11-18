import random

alpha = input().strip()
alpha = alpha.replace('^', '**')
alpha = alpha.replace(' ', '')
n = int(input())
check_exps = []
for x in range(0, n):
    line = input().strip()
    line = line.replace('^', '**')
    line = line.replace(' ', '')
    check_exps.append(line)
    pass

check_nums = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 
41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 
97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151]
match = {}
for x in check_nums:
    ans = eval(alpha.replace('a', str(x)))
    match[x] = ans
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