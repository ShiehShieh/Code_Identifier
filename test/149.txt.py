f=[]
text=raw_input()
f=text.split(" ")
h=input()
n=10
for i in range(0,10):
  if int(f[i])>(h+30):
    n-=1
  
print n