import sys
import random

alpha = sys.stdin.readline().strip()
alpha = alpha.replace('^', '**')
alpha = alpha.replace(' ', '')
n = int(sys.stdin.readline().strip())
check_exps = []
for x in range(0, n):
    line = sys.stdin.readline().strip()
    line = line.replace('^', '**')
    line = line.replace(' ', '')
    check_exps.append(line)
    pass

check_nums = [7907, 7919]
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