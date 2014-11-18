for i in range(input()):
	m=[0]*127
	for x in raw_input():m[ord(x)]+=1
	print 'Case #'+str(i+1)+':',min(m[32],m[ord('g')]/2,m[ord('o')]/3,m[ord('d')],m[ord('m')],m[ord('r')],m[ord('n')]/2,m[ord('i')])