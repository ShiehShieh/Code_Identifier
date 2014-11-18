#include<iostream>
using namespace std;
struct stu{
	char name[20];
	int term;
	int cla;
	char cadre;
	char west;
	int num,sum;
}student[100];
int main()
{
	int n,i,j,max=0,s=0;
	cin>>n;
    for(i=0;i<n;i++)
	{
		cin>>student[i].name;
		cin>>student[i].term>>student[i].cla>>student[i].cadre>>student[i].west>>student[i].num;
		student[i].sum=0;
	}
	for(i=0;i<n;i++)
	{
		if(student[i].term>80&&student[i].num>=1)
			student[i].sum+=8000;
		if(student[i].term>85&&student[i].cla>80)
			student[i].sum+=4000;
		if(student[i].term>90)
			student[i].sum+=2000;
		if(student[i].term>85&&student[i].west=='Y')
			student[i].sum+=1000;
		if(student[i].cla>80&&student[i].cadre=='Y')
			student[i].sum+=850;
	}
	for(i=0;i<n;i++)
	{
		if(student[i].sum>max)
		{
			max=student[i].sum;
			j=i;
		}
		
	}
    for(i=0;i<n;i++)
	{
		s+=student[i].sum;
	}
	cout<<student[j].name<<endl;
	cout<<max<<endl;
	cout<<s;
	return 0;
}
