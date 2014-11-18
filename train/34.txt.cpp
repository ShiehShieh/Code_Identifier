#include<stdio.h>
struct std
{
 long l,r,lc,rc,maxx;
}tr[400001];
long n,m,date[200001],size;
int maxex(int a,int b)
{
    if(a>b)return a;
    return b;
} 
void build(int left,int right)
{
   int temp;
   size++;temp=size;
   tr[temp].l=left;tr[temp].r=right;  
   if(left==right){
                   tr[temp].maxx=date[left];
                   return ;
                  }
   tr[temp].lc=size+1;
   build(left,(left+right)/2);
   tr[temp].rc=size+1;
   build((left+right)/2+1,right);
   tr[temp].maxx=maxex(tr[tr[temp].lc].maxx,tr[tr[temp].rc].maxx);
}
int search(int left,int right,int num)
{
  if(left==tr[num].l&&right==tr[num].r)return tr[num].maxx;
  if(left==right)return date[left];
  if(right<=(tr[num].l+tr[num].r)/2)return search(left,right,tr[num].lc);
  if(left>(tr[num].l+tr[num].r)/2)return search(left,right,tr[num].rc);
  return maxex(search(left,(tr[num].l+tr[num].r)/2,tr[num].lc),search((tr[num].l+tr[num].r)/2+1,right,tr[num].rc));
}
int main()
{
    int i,a,b;
   scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&date[i]);
    size=0;
    build(1,n);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
     scanf("%d %d",&a,&b);
     printf("%d",search(a,b,1));
    }
    return 0;
}

