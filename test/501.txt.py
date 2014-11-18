while 1:
    n,k = map(int,raw_input().split())
    if n == 0 and k == 0:
        break
    vals = map(int,raw_input().split())
    decs = map(int,raw_input().split())
    data = map(lambda x,y:(x,y),decs,vals)
    data.sort(reverse = True)
    r1 = [0 for i in range(k+1)]
    r = [r1[:] for i in range(n+1)]
    result = 0
    for i in range(1,n+1):
        for j in range(1,k+1):
            val = data[i-1][1] - data[i-1][0]*(j-1)
            if val < 0:
                val = 0
            try:
                r[i][j] = max(r[i-1][j],r[i-1][j-1] + val)
            except Exception as e:
                print i,j
                print len(r[i])
            result = max(result, r[i][j])
    print result