#include<stdio.h>
int n; 
struct v
{
char name[20]; 
int money;
}line[1000]; 
char s[20];
int search ()
{
int i,j,f;
for (i=1; i<=n;i++)
{ 
    j=0;f=1;
    while  ( ((s[j]>='a') && (s[j]<='z'))
    || ((s[j]>='A')&&(s[j]<='Z')) )
    if (line[i].name[j]==s[j]) j++; else {f=0; break; }
    if  (f) return i;
    }
    }
void work ()
{
     int i,j,k,pm,pn; 
     for (i=1;i<=n;i++)
     {
         scanf ("%s",&s); 
         k=search ();
         scanf ("%d%d",&pm,&pn);
         if (pn>0) line[k].money=line[k].money-(pm/pn)*pn;
         for (j=1;j<=pn;j++)
         {
             scanf ("%s",&s); 
             k=search (); 
             line[k].money=line[k].money+pm/pn;
             }
         }
}
void outf ()
{
     int i;
     for (i=1;i<=n;i++)
     printf ("%s %d\n",line[i].name,line[i].money);  
}
int main ()
{
    int i;
    scanf ("%d",&n); 
    for (i=1;i<=n;i++) scanf ("%s",&line[i].name);
    work ();
    outf ();
    return 0; 
}
