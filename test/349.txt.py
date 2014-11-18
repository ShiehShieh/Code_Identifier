count = int(raw_input())
ds = []
class node:
    def setinof(self, name, fen1, fen2, ganbu, xibu, nub):
        self.name = name
        self.fen1 = int(fen1)
        self.fen2 = int(fen2)
        self.ganbu = ganbu
        self.xibu = xibu
        self.nub = int(nub)

def getmoney(n):
    rst = 0
    if n.nub >= 1 and n.fen1 > 80:
        rst += 8000
    if n.fen2 > 80 and n.fen1 > 85:
        rst += 4000
    if n.fen1 > 90:
        rst += 2000
    if n.fen1 > 85 and n.xibu == 'Y':
        rst += 1000
    if n.fen2 > 80 and n.ganbu == 'Y':
        rst += 850
    return [n.name, rst]

        
for i in range(count):
    s = raw_input().split(' ')
    x = node()
    x.setinof(*s)
    ds.append(x)

rst = map(getmoney, ds)
maxn = max(rst, key=lambda x: x[1])
sumf = sum([p[1] for p in rst])
print(maxn[0])
print(maxn[1])
print(sumf)