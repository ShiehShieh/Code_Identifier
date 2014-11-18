import sys
L = int(sys.stdin.readline())
S, T, M = map(int, sys.stdin.readline().split(' '))
stones = map(int, sys.stdin.readline().split(' '))
#print (S,T,M)
#print (stones)
if S==T:
    total = 0
    for stone in stones:
        if stone > L:
            break
        if stone % S == 0:
            total += 1
    print(total)
else:
    min_stones = [0]
    pos = T-1
    MAX = len(stones)+1
    
    for i in range(1, S):
        min_stones.append(MAX)
    for i in range(S, T):
        min_stones.append(0)
    for stone in stones:
        if stone > L:
            break
        if stone < S:
            continue
        if stone < T:
            min_stones[stone] = 1
            continue
        
        min_v = MAX
        for i in range(pos+1, stone):
            for j in range(S, T+1):
                k = (i - j) % T
                if min_stones[k] < min_v:
                    min_v = min_stones[k]
            min_stones[i % T] = min_v;
        min_stones[stone % T] += 1
        pos = stone+T

    min_v = MAX
    for i in range(pos+1, L+1):
        for j in range(S, T+1):
            k = (i - j) % T
            if min_stones[k] < min_v:
                min_v = min_stones[k]
        min_stones[i % T] = min_v;
    print (min(min_stones))
    
            
