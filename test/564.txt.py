x=r=input();l=0
while l+1<r:
	m=int((l+r)/2)
	if m*m*m+m*m+3*m<=x:
		l=m
	else:
		r=m
print l