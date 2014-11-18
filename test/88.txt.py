class Student(object):
    def __init__(self, info):
        self.name, self.f_avg, self.c_avg, self.bu, self.west, self.lect = info.split(' ')
        self.f_avg = int(self.f_avg)
        self.c_avg = int(self.c_avg)
        self.lect = int(self.lect)

    def type1(self):
        return self.f_avg > 80 and self.lect >= 1

    def type2(self):
        return self.f_avg > 85 and self.c_avg > 80

    def type3(self):
        return self.f_avg > 90

    def type4(self):
        return self.f_avg > 85 and self.west == 'Y'

    def type5(self):
        return self.c_avg > 80 and self.bu == 'Y'

    def total(self):
        ret = 0
        if self.type1(): ret += 8000
        if self.type2(): ret += 4000
        if self.type3(): ret += 2000
        if self.type4(): ret += 1000
        if self.type5(): ret += 850
        return ret

la = []
le = []
n = int(raw_input())
for _ in range(n):
    s = Student(raw_input())
    la.append([s.name, s.total()])
    le.append(s.total())

def get_key(a):
    return a[-1]

m = max(la, key=get_key)
print m[0]
print m[-1]
print sum(le)