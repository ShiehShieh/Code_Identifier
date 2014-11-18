#include<iostream>
using namespace std;

struct stu
{
char name[25];
int final;
int group;
char leader;
char west;
int acd;
int scol;
};

stu scolar[100];

int main()
{
int n;
cin>>n;
stu max;
max.scol=-1;
double total=0;
int i;
for(i=0;i<n;i++)
{

cin>>scolar[i].name>>scolar[i].final>>scolar[i].group>>scolar[i].leader>>scolar[i].west>>scolar[i].acd;
scolar[i].scol=0;
if(scolar[i].final>80&&scolar[i].acd>=1)
scolar[i].scol+=8000;
if(scolar[i].final>85&&scolar[i].group>80)
scolar[i].scol+=4000;
if(scolar[i].final>90)
scolar[i].scol+=2000;
if(scolar[i].final>85&&scolar[i].west=='Y')
scolar[i].scol+=1000;
if(scolar[i].group>80&&scolar[i].leader=='Y')
scolar[i].scol+=850;


if(scolar[i].scol>max.scol)
{
max.scol=scolar[i].scol;
strcpy(max.name,scolar[i].name);
}
total+=scolar[i].scol;


}
printf("%s\n%d\n%.0lf",max.name,max.scol,total);

} 

