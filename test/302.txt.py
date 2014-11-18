a = input()
name=[]
money=[]
for i in range(0,a):
    nametmp,ave,clas,lead,west,paper=raw_input().split(' ')
    name.append(nametmp)
    money.append(0)
    if (int(ave)>80)and(int(paper)>=1):
        money[i]=money[i]+8000
    if (int(ave)>85)and(int(clas)>80):
        money[i]=money[i]+4000
    if (int(ave)>90):
        money[i]=money[i]+2000
    if (int(ave)>85)and(west=="Y"):
        money[i]=money[i]+1000
    if (int(clas)>80)and(lead=="Y"):
        money[i]=money[i]+850

max=0
total=0
for i in range(0,a):
    total=total+money[i]
    if (money[i]>max):
        maxname=name[i]
        max=money[i]
if (max>0):
    print maxname
    print max
    print total
    
