L = int(raw_input())
S, T, M = raw_input().split(' ')
S = int(S)
T = int(T)
M = int(M)
N = 0
curr_pos = 0
last_cand = 0
array = [0 for n in range(T)]

stones = raw_input().split(' ')
for i in range(M):
    a = int(stones[i])
    if S == T:
        if a % T == 0:
            N += 1
    else:
        mod = i % T
        min_v = 1000
        for i in range(S,T):
            if a - i < 0:
                continue 
            pos = (a - i + T) % T
            if array[pos] < min_v:
                min_v = array[pos]
        array[mod] = min_v + 1

if S != T:
    N = 1000
    for i in range(T):
        if array[i] < N:
            N = array[i]

print N