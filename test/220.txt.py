n=int(raw_input())
name=""
max=0
total=0

for i in xrange(n):
        line=raw_input().split(' ')
        line[1]=int(line[1])
        line[2]=int(line[2])

        money=0
        if ((line[1]>80)and(line[5]!="0")):
                money+=8000
        if ((line[1]>85)and(line[2]>80)):
                money+=4000
        if (line[1]>90):
                money+=2000
        if ((line[1]>85)and(line[4]=="Y")):
                money+=1000
        if ((line[2]>80)and(line[3]=="Y")):
                money+=850
        total+=money
        if (money>max):
                max=money
                name=line[0]
print name
print max
print total