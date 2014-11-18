l= 10
s,t ,m = 2, 3, 5
date = [2,3,5,6,7]

l = int(raw_input())
s, t, m = map(int, raw_input().split(' '))
date = map(int, raw_input().split(' '))

td = set(date)
tmap = {}
def f(n):
    if n <= t:
        return 0
    else:
        tmp = [n - i for i in range(s, t+1) if n - i in td]
        rst = map(lambda x: f(x) + 1, tmp)
        rst.append(10^9)
        x = min(rst)
        tmap[n] = x
        return x
print f(l)