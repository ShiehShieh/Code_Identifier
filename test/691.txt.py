from fractions import Fraction
q=int(raw_input())
b=q**Fraction(1,3)
b=int(b)
if b**3+b**2+b*3>q:
	print b-1
else:
	print b