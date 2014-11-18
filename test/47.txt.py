n = input()
m = input()

apple = [x for x in range(0, 300)]
idx = 1
for i in range(0, m):
    jump = idx + pow(i + 1, 3) % 5 + 1
    if jump > n - i:
        jump = 1 + pow(i + 1, 3) % 5 + 1
    idx = jump
    eat = apple[idx]
    for j in range(idx, n - i + 1):
        apple[j] = apple[j + 1]

print eat
