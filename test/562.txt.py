s=t=0
for i in range(12):
	s+=300;s-=input()
	if s<0: print -1-i;exit();
	t+=s/100;s=s%100
print t*120+s