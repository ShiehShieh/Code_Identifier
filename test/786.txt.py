import string
num=raw_input()
snum=string.split(num)
n,m,k,x=int(snum[0]),int(snum[1]),int(snum[2]),int(snum[3])
temp=pow(10,k,n)
ans=(x+m*temp)%n
print ansa