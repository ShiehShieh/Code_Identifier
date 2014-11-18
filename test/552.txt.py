n,m,k,x = [int(x) for x in raw_input().split()]
print ((m*pow(10,k,n))%n+x)%n
