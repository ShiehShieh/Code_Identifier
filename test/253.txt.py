def calculate(info):
    out = 0
    info[1] = int(info[1])
    info[2] = int(info[2])
    info[5] = int(info[5])

    if info[1] > 80 and info[5] > 0:
        out += 8000
    if info[1] > 85 and info[2] > 80:
        out += 4000
    if info[1] > 90:
        out += 2000
    if info[1] > 85 and info[4] == 'Y':
        out += 1000
    if info[2] > 80 and info[3] == 'Y':
        out += 850
    return out


if __name__ == '__main__':
    n = int(raw_input())

    maxNum = 0
    total = 0
    for i in range(n):
        info = raw_input().split(' ')

        out = calculate(info)

        total += out
        if out > maxNum:
            maxNum = out
            name = info[0]

    print name
    print maxNum
    print total
