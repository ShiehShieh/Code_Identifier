#include <stdio.h>
#include <string.h>
struct water
{
char name[20];
char num[10000];
};
water person[1000];
int compare(int a1, int a2 )
{
int len1,len2,t;
len1=strlen(person[a1].num);
len2=strlen(person[a2].num);
if(len1==len2)
{
t=strcmp(person[a1].num,person[a2].num);
if(t==0)
{
t=strcmp(person[a1].name,person[a2].name);
return t; 
}
else
{
return -t;
} 
}
else
{
return len2-len1;
}
}
main()
{
int n,i,j;
char temp[10000];
int k;
scanf("%d\n",&n);
for(i=0;i<n;i++)
{
gets(person[i].name);
gets(person[i].num);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
k=compare(i,j);
if(k>0)
{
strcpy(temp,person[i].name);
strcpy(person[i].name,person[j].name);
strcpy(person[j].name,temp);
strcpy(temp,person[i].num);
strcpy(person[i].num,person[j].num);
strcpy(person[j].num,temp);
}
}
}
for(i=0;i<n;i++)
{
printf("%s\n",person[i].name);
}
scanf("%d",&n);
} 
