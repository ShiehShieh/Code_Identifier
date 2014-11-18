flag = 0
use = [0 for x in range(7)]
num = [0 for x in range(7)]
char = [" " for x in range(7)]
def dfs(nowsum,step):
    global flag
    if flag == 1:return
    if step == 4 and (nowsum - 24)**2 < 0.000001:
        flag = 1
        print "1"
        return
    for i in range(0,4):
        if use[i] == 0:
            use[i] = 1
            dfs(nowsum+num[i],step+1)
            dfs(nowsum-num[i],step+1)
            dfs(num[i]-nowsum,step+1)
            dfs(num[i]*nowsum,step+1)
            dfs(nowsum/num[i],step+1)
            if nowsum != 0: dfs(num[i]/nowsum,step+1)
            use[i] = 0
    return

char = [str(x) for x in raw_input().split()]
for i in range(0,4):
    if char[i] == 'A': num[i] = 1
    elif char[i] == 'J': num[i] = 11
    elif char[i] == 'Q': num[i] = 12
    elif char[i] == 'K': num[i] = 13
    else: num[i] = int(char[i])
for i in range(0,4):
    if use[i] == 0:
        use[i] = 1
        dfs(float(num[i]),1)
        use[i] = 0
if flag == 0 : print "0"
