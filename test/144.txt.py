max=0;total=0;jxj=0;
n=raw_input()
for i in range(1,int(n)+1):
  name,ave,py,gb,xb,lw=raw_input().split(" ")
  if (int(ave)>80) and (int(lw)>0):
    jxj+=8000
  if (int(ave)>85) and (int(py)>80):
    jxj+=4000
  if (int(ave)>90):
    jxj+=2000
  if (int(ave)>85) and (xb=='Y'):
    jxj+=1000
  if (int(py)>80) and (gb=='Y'):
    jxj+=850
  if jxj>max: 
    max=jxj;maxname=name;
  total+=jxj;jxj=0
  
print maxname
print max
print total
