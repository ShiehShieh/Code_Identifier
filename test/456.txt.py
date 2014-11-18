t = int(input())
max = 0
total = 0
who = ''
for i in range(t):
    a,b,c,d,e,f = raw_input().split()
    b = int(b)
    c = int(c)
    f = int(f)
    award = 0
    if (b > 80 and f > 0):
        award += 8000
    if (b > 85 and c > 80):
        award += 4000
    if (b > 90):
        award += 2000
    if (b > 85 and e == 'Y'):
        award += 1000
    if (c > 80 and d == 'Y'):
        award += 850
    if (award > max):
        max = award
        who = a
    total += award
print(who)
print(max)
print(total)
    