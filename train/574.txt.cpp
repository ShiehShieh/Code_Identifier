/*  Vijos P1335  */

#include<iostream>
using namespace std;

int map[9][9];
bool IsOk(int nx,int ny){
int aa[10]={0};
for (int i=nx;i<nx+3;i++)
for (int j=ny;j<ny+3;j++)
aa[map[i][j]]++;
for (int i=1;i<=9;i++)
if (aa[i]!=1) return false;
return true;
}

void work()
{
for (int i=0;i<9;i++)
for (int j=0;j<9;j++)
cin>>map[i][j];
for (int i=0;i<9;i++){
int aa[10]={0};
for (int j=0;j<9;j++)
aa[map[i][j]]++;
for (int j=1;j<=9;j++)
if (aa[j]!=1) goto loop;
}
for (int j=0;j<9;j++){
int aa[10]={0};
for (int i=0;i<9;i++)
aa[map[i][j]]++;
for (int j=1;j<=9;j++)
if (aa[j]!=1) goto loop;
}
if (!IsOk(0,0))goto loop;
if (!IsOk(0,3))goto loop;
if (!IsOk(0,6))goto loop;
if (!IsOk(3,0))goto loop;
if (!IsOk(3,3))goto loop;
if (!IsOk(3,6))goto loop;
if (!IsOk(6,0))goto loop;
if (!IsOk(6,3))goto loop;
if (!IsOk(6,6))goto loop;
cout<<"Right"<<endl;return;
loop:cout<<"Wrong"<<endl;
}

int main (void)
{
int n;
cin>>n;
for(;n>=1;n--)
work();
return 0;
}
