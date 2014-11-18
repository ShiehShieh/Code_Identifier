def dfs(index):
    global time
    flag[index] = 1
    for i in range(n):
        if graph[index][i] == 1 and flag[i] == 0:
            dfs(i)
    time += 1
    seq[time] = index

def dfs_r(index):
    global time
    flag[index] = 1
    for i in range(n):
        if graph[i][index] == 1 and flag[i] == 0:
            dfs_r(i)

n = input()
graph = [[0 for x in range(n)] for x in range(n)]
flag = [0 for x in range(n)]
seq = [0 for x in range(n)]
time = -1
segment = 0

for i in range(n):
    temp = [int(x) for x in raw_input().split()]
    temp.remove(0)
    if temp != None:
        temp = [x - 1 for x in temp]
        for node in temp:
            graph[i][node] = 1

for i in range(n):
    if flag[i] == 0:
        dfs(i)
    
seq.reverse()
flag = [0 for x in range(n)]

for i in range(n):
    if flag[i] == 0:
        segment += 1
        dfs_r(i)

print segment
