
a = []

n = int ( raw_input () )
kingNum = [ int ( i ) for i in raw_input ().split () ]
for i in xrange ( 0, n ):
	tmpA, tmpB = [ int ( i ) for i in raw_input ().split () ]
	a.append ( ( tmpA * tmpB, tmpA, tmpB ) )

a.sort ()
tmp = kingNum[ 0 ]
answer = int ( tmp / a[ 0 ][ 2 ] )
for i in xrange ( 1, n ):
	tmp *= a[ i - 1 ][ 1 ]
	answer = max ( answer, int ( tmp / a[ i ][ 2 ] ) )

print answer