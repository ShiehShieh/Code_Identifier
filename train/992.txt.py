while 1:
    n,k = map(int,raw_input().split())
    if n == 0 and k == 0:
        break
    vals = map(int,raw_input().split())
    decs = map(int,raw_input().split())
    data = map(lambda x,y:(x,y),decs,vals)
    data.sort(reverse = True)
    r = []
    r.append([0 for i in range(n)])
    for i in range(1,k+1):
        r.append([])
        r[i].append(0)
        for j in range(1,n+1):
            val = data[j-1][1] - data[j-1][0]*(i-1)
            if val < 0:
                val = 0 
            temp = max(r[i][j-1],r[i-1][j-1] + val)
            r[i].append(temp)
    result = max(r[k])
    print result