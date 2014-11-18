#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    char id;
    char name[30];
    int finalscore;
    int classscore;
    char monitor;
    char west;
    int article;
    int money;
}student[105];

int cmp(const void *a,const void *b)
{
     struct node *c=(node *)a;
     struct node *d=(node *)b;
     if(c->money!=d->money)  return d->money-c->money;
     else return c->id-d->id;

}

int main()
{
    int i,n,sum=0;
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s %d %d %c %c %d",student[i].name,&student[i].finalscore,&student[i].classscore,&student[i].monitor,&student[i].west,&student[i].article);
        student[i].id=i;
        if(student[i].finalscore>80&&student[i].article>0)
           student[i].money+=8000;
        if(student[i].finalscore>85&&student[i].classscore>80)
           student[i].money+=4000;
        if(student[i].finalscore>90)
           student[i].money+=2000;
        if(student[i].finalscore>85&&student[i].west=='Y')
           student[i].money+=1000;
        if(student[i].classscore>80&&student[i].monitor=='Y')
           student[i].money+=850;

        sum+=student[i].money;
    }
    qsort(student+1,n,sizeof(node),cmp);
    
    printf("%s\n",student[1].name);
    printf("%d\n",student[1].money);
    printf("%d\n",sum);
    
    return 0;
}
    
    
    

