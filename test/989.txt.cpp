#include<iostream>
using namespace std;
long *app,*ttw,*ttwp,*ttapp;
int cmp(const void * a,const void * b)
{
 return -ttw[*((long*)a)] + ttw[*((long*)b)];
}
int cmp1(const void * a,const void * b)
{
 return -*((long*)a) + *((long*)b);
}

int main()
{
 long n,m;
 cin >> n >> m;
 app = new long[n];
 ttw = new long[m];
 ttwp = new long[m];
 ttapp = new long[m];
 for(int i = 0;i < n;i++)
  cin >> app[i];
 for(int i = 0;i < m;i++)
 {
  cin >> ttw[i];
  ttwp[i] = i;
  ttapp[i] = 0;
 }
 qsort(ttwp,m,sizeof(long),cmp);
 qsort(app,n,sizeof(long),cmp1);
 int k = 0;
 for(int i = 0;i < n;i++)
 {
  ttapp[ttwp[k]] += app[i];
  k++;
  if(k == m)k = 0;
 }
 for(int i = 0;i < m;i++)
  cout<<ttapp[i]<<' ';
 return 0;
}
