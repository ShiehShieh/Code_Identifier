def checkSafety(data):
    dic = dict()

    for i in range(len(data)):
        temp = data[i]
        if temp in dic:
            dic[temp] += 1
        else:
            dic[temp] = 1

    count = 0
    for value in dic.values():
        if value >= 2:
            count += 1

    print dic

    if count >= 2:
        print 'de1ete'
    else:
        print 'safe'


if __name__ == '__main__':
    n = int(raw_input())

    for i in range(n):
        temp = raw_input()
        checkSafety(temp)
