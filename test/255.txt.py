def dfs(index):
    flag[index] = 1

    for i in range(n):
        if graph[index][i] == 1 and flag[i] == 0:
            dfs(i)
    
n = input()
graph = [[0 for x in range(n)] for x in range(n)]
degree = [0 for x in range(n)]
flag = [0 for x in range(n)]
segment = 0

for i in range(n):
    temp = [int(x) for x in raw_input().split()]
    temp.remove(0)
    if temp != None:
        temp = [x - 1 for x in temp]
        for node in temp:
            graph[i][node] = 1
            degree[node] += 1
        
for i in range(n):
    if flag[i] == 0:
        segment += 1
        dfs(i)

print segment