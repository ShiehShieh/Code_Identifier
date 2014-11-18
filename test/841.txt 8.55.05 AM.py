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