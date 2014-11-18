def checkSafety(data):
    dic = dict()

    for i in range(len(data)):
        temp = data[i]
        if temp in dic:
            a,b  = dic[temp]
            dic[temp] = (a,i)
            for key in dic:
                if key != temp:
                    c,d = dic[key]
                    if a < d and c < d:
                        #print dic
                        print 'de1ete'
                        return
        else:
            dic[temp] = (i,i)
    print 'safe'



if __name__ == '__main__':
    n = int(raw_input())

    for i in range(n):
        temp = raw_input()
        checkSafety(temp)
