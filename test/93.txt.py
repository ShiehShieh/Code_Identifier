m = 0
n = 0
for i in range(0,int(raw_input())):
    t = raw_input().split(' ')
    t = [t[0],int(t[1]),int(t[2]),t[3]=='Y',t[4]=='Y',int(t[5])]
    s = 160 * ((t[1]>80) and (t[5]>0)) + 80 * ((t[1]>85) and (t[2]>80)) + 40 * (t[1]>90) + 20 * ((t[1]>85) and t[4]) + 17 * ((t[2]>80) and t[3])
    if s > m:
        k = t[0]
        m = s
    n += s
print k
print m * 50
print n * 50