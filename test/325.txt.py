import sys
sum_of_all=0
sum=0
winner=''
def cal():
	global sum_of_all,sum,winner
	line=sys.stdin.readline()
	a=line.split()
	name=a[0]
	average=int(a[1])
	class_score=int(a[2])
	W1=a[3]
	W2=a[4]
	num=int(a[5])
	temp=0
	if (average>80) and (num>=1):
		temp=temp+8000
	if (average>85) and(class_score>80):
		temp=temp+4000
	if (average>90):
		temp=temp+2000
	if (average>85) and (W2=='Y'):
		temp=temp+1000
	if (class_score>80) and (W1=='Y'):
		temp=temp+850
	sum_of_all=sum_of_all+temp
	if temp>sum:
		sum=temp
		winner=name
N=int(raw_input())
for i in range(1,N+1):
	cal()
print "%s" %(winner)
print "%d" %(sum)
print "%d" %(sum_of_all)