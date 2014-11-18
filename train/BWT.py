def rot(v):
        return v[-1] + v[:-1]

def bwt_matrix(s):
        return sorted(reduce(lambda m,s : m + [rot(m[-1])],xrange(len(s)-1),[s]))

def last_column(m):
        return ''.join(zip(*m)[-1])

def bwt(s):
        bwtm = bwt_matrix(s)
        print 'BWT matrix : ', bwtm
        return bwtm.index(s), ''.join(last_column(bwtm))

def transpose(m):
        return [''.join(i) for i in zip(*m)]

def ibwt(s):
        return reduce(lambda m, s: transpose(sorted(transpose([s]+m))),[s]*len(s),[])

s = 'sixtysix'
index, bwts = bwt(s)
print 'BWT, index : ', bwts, index
print 'iBWT : ', ibwt(bwts)
