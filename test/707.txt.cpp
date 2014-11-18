#include <iostream>
#include <fstream>
using namespace std;
char f[9][9]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
int s[9];
char mins[55];
int g[9];
void ok()
{
int i,j;
for (i=0;i<9;i++) if (g[i]) return;
char mm[55];
int m=0;
for (i=0;i<9;i++)
for (j=0;j<s[i];j++)
{
mm[m]='0'+i;
m++;
}
mm[m]='\0';
if (strlen(mm)>strlen(mins))return;
if (strlen(mm)<strlen(mins))
{
strcpy(mins,mm);
return ;
}
if (strcmp(mm,mins)<0) strcpy(mins,mm);
}
void move(int k)
{
int i,l=strlen(f[k]);
for (i=0;i<l;i++)
{
int j=(int)(f[k][i]-'A');
g[j]=(g[j]+1)%4;
}
}
void dfs(int k)
{
if (k>=9) {ok();return;}
for (s[k]=0;s[k]<4;s[k]++)
{
dfs(k+1);
move(k);
}
s[k]=0;
}
void oot()
{
int i,l=strlen(mins);
for (i=0;i<l-1;i++)
cout<<(int)(mins[i]-'0'+1)<<' ';
cout<<(int)(mins[i]-'0'+1)<<endl;
}
int main()
{
int i;
for (i=0;i<9;i++) {cin>>g[i];s[i]=0;}
for (i=0;i<55;i++) mins[i]='9';mins[54]='\0';
dfs(0);
oot();
return 0;
}
 
 

