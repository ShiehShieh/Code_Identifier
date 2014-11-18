n, m = [int(x) for x in raw_input().split()]

bitmap = []

for i in range(n):
    line = raw_input()
    bitmap.append(list(line))

def floodfill(r, c):
    global bitmap
    bitmap[r][c] = '-'

    for i in range(-2, 3):
        for j in range(-2, 3):
            new_r = r + i
            new_c = c + j
            if new_r >= 0 and new_c >= 0 and new_r < n and new_c < m \
                    and bitmap[new_r][new_c] == '#' and abs(new_r - r) + abs(new_c - c) <= 2:
                floodfill(new_r, new_c)


num = 0
for i in range(n):
    for j in range(m):
        if bitmap[i][j] == '#':
            num += 1
            floodfill(i, j)

print num
