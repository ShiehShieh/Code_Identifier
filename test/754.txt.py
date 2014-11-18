n = int(input())
x = n**(1/2)
x = int(x)
for i in range(2,x+1):
    if ( n%i == 0 ):
        print ( n//i )
        break
