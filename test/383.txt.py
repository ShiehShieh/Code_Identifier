#!/usr/bin/python
import sys

def sort(num,cmp, start = 0, end = None):
    if(end == None):
        end = len(num)
    if end - start <= 1:
        return num
    mid = num[end-1]
    #print("mid:%s"%mid)
    idx = start
    for i in range(start, end):
        if cmp(int(num[i]),int(mid)) < 0:
            tmp = num[idx]
            num[idx] = num[i]
            num[i] = tmp
            idx+=1
    tmp=num[idx]
    num[idx] = num[end-1]
    num[end-1] = tmp
    sort(num, cmp, start, idx)
    sort(num, cmp, idx+1, end)
    return num

def solve(num):
    size = len(num)
    mem = {}
    mem[int(num)] = 0
    res = [int(num)]
    while True:
        arr = list(num)
        #print("before sort")
        #print(num)
        minv = "".join(sort(arr[:], cmp=lambda x,y: x-y))
        maxv = "".join(sort(arr[:], cmp=lambda x,y: y-x))
        #print("after sort")
        #print(minv)
        #print(maxv)
        r = int(maxv) - int(minv)
        if mem.get(r) is None:
            mem[r] = len(res)
            res.append(r)
            num = str(r)
            num = "0"*(size - len(num))+num
        else:
            return " ".join([str(x) for x in res[mem[r]: len(res)]])
            #print(" ".join(res[mem[r]: len(res)]))
            #return

for line in sys.stdin:
    #print(line)
    print(solve(line.strip()))