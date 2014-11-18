day=0;max=0;
for i in range(1,8):
  a,b=raw_input().split(" ")
  t=int(a)+int(b)-8
  if t>max:
    max=t;day=i;
print day