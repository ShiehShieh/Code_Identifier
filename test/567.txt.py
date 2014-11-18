n=raw_input()
n=int(n)
num=1
for i in range(1,n+1):
    num*=i;
ans=0
while num>0:
    ans+=(num%10)
    num/=10
x=int((ans+0.5)**0.5)
flag=1
for i in range(2,x+1):
    if ans%i==0:
        flag=0
        break
if flag==1:
    print str(ans)+"T"
else:
    print str(ans)+"F"
