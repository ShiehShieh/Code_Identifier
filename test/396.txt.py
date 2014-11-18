n=int(raw_input())
a,ans=[],[]
tot,totans=0,0
for i in range(n):
    a=raw_input().split(' ')
    now=0
    if int(a[1])>80 and int(a[5]):
        now=now+8000
    if int(a[1])>85 and int(a[2])>80:
        now=now+4000
    if int(a[1])>90:
        now=now+2000
    if int(a[1])>85 and a[4]=='Y':
        now=now+1000
    if int(a[2])>80 and a[3]=='Y':
        now=now+850
    tot=tot+now
    if totans<now:
        totans=now
        ans=a
print ans[0]
print totans
print tot
