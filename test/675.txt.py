n=input(int)
money=[0]*n
m=[' ']*n
wst=0
for i in range(0,n):
    name,score1,score2,gb,west,lw=raw_input().split(' ')
    if (int(score1)>80) and (int(lw)>0):
        money[i]+=8000
    if (int(score1)>85) and (int(score2)>80):
        money[i]+=4000
    if int(score1)>90:
        money[i]+=2000
    if (int(score1)>85) and (west=='Y'):
        money[i]+=1000
    if (int(score2)>80) and (gb=='Y'):
        money[i]+=850
    wst+=money[i];
    m[i]=name
for i in range(0,n):
    if max(money)==money[i]:
        print m[i]
        break
print max(money)
print wst