#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct node
{
	string name;
	int endGrade;
	int classGrade;
	bool crade;
	bool west;
	int eNum;
	int num;
	int sum;
}stu[101];
int comp(node a,node b)
{
	return a.sum>b.sum;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		char ch1,ch2;
		int totalSum=0;
		for(i=0;i<n;i++)
		{
			cin>>stu[i].name;
			scanf("%d%d",&stu[i].endGrade,&stu[i].classGrade);
			cin>>ch1>>ch2;
			if(ch1=='Y')
				stu[i].crade=true;
			else if(ch1=='N')
				stu[i].crade=false;
			if(ch2=='Y')
				stu[i].west=true;
			else if(ch2=='N')
				stu[i].west=false;
			scanf("%d",&stu[i].eNum);
			stu[i].num=i;
			stu[i].sum=0;
		}
		for(i=0;i<n;i++)
		{
			if(stu[i].endGrade>80&&stu[i].eNum>=1)
			{
				stu[i].sum+=8000;
				totalSum+=8000;
			}
			if(stu[i].endGrade>85&&stu[i].classGrade>80)  //主要注意这里每个都是if,而不是else if如果用else if那么关系就错了
			{
				stu[i].sum+=4000;
				totalSum+=4000;
			}
			if(stu[i].endGrade>90)
			{
				stu[i].sum+=2000;
				totalSum+=2000;
			}
			if(stu[i].endGrade>85&&stu[i].west)
			{
				stu[i].sum+=1000;
				totalSum+=1000;
			}
			 if(stu[i].classGrade>80&&stu[i].crade)
			{
				stu[i].sum+=850;
				totalSum+=850;
			}
		}
		sort(stu,stu+n,comp);
		int temp=stu[0].sum,tempNum=stu[0].num,k=0;
		for(i=1;i<n;i++)
		{
			if(stu[i].sum<temp)
				break;
			else if(stu[i].num<tempNum)
			{
				tempNum=stu[i].num;
				k=i;
			}
		}
		cout<<stu[k].name<<endl;
		printf("%d\n%d\n",stu[k].sum,totalSum);
	}
	return 0;
}
