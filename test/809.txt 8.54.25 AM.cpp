#include<stdio.h>
int main()
{
	struct student
	{
		char name[21];
		int qm,bp,lw;
		char xs,xb;
	}stu[105];
	int i,n;
	while(scanf("%d%*c",&n)!=EOF)
	{
		int max=0,id=0,sum=0;
		for (i=0;i<n;i++)
		{
			int total=0;
			scanf("%s %d %d %c %c %d",stu[i].name,&stu[i].qm,&stu[i].bp,&stu[i].xs,&stu[i].xb,&stu[i].lw);
			if (stu[i].qm>80&&stu[i].lw>=1) total+=8000;
			if (stu[i].qm>85&&stu[i].bp>80) total+=4000;
			if (stu[i].qm>90) total+=2000;
			if (stu[i].qm>85&&stu[i].xb=='Y') total+=1000;
			if (stu[i].bp>80&&stu[i].xs=='Y') total+=850;
			if (total>max) {max=total;id=i;}
			sum+=total;
		}
		printf("%s\n",stu[id].name);
		printf("%d\n",max);
		printf("%d\n",sum);
	}
	return 0;
}
