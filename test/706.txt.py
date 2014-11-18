#!/usr/bin/env python2
#p1001
i = int(raw_input())
kw = []

def getmoney(qm, bj, gb, xb, lw):
		mn = 0
		if int(qm)>80 and int(lw)>=1:
				mn+=8000
		if int(qm)>85 and int(bj)>80:
				mn+=4000
		if int(qm)>90:
				mn+=2000
		if int(qm)>85 and xb=="Y":
				mn+=1000
		if int(bj)>80 and gb=="Y":
				mn+=850
		return mn

tot = 0
for i in range(0, i, 1):
		l = raw_input()
		ls = l.split(" ")
		kw.append((getmoney(*ls[1:]), ls[0]))

for i in kw:
		tot += i[0]

kw = sorted(kw, key=lambda x: x[0])
print kw[-1][1]
print kw[-1][0]
print tot
