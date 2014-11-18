/*
----------------->n
|(0,0)
|
|
|
|
|
\/m               B.(n,m)
*/
#include<iostream>
using namespace std;
int n,m,mx,my,k=0;
bool s[15][15];
void settrue()
{
 for(int i = 0;i < 16;i++)
  for(int j = 0;j < 16;j++)
   s[i][j] = true;
}
void setfalse()
{
 s[mx][my] = false;
 if(mx - 1 >= 0)
 {
  if(my - 2 >= 0)s[mx-1][my-2]=false;
  if(my + 2 <= m)s[mx-1][my+2]=false;
 }
 if(mx + 1 <= n)
 {
  if(my - 2 >= 0)s[mx+1][my-2]=false;
  if(my + 2 <= m)s[mx+1][my+2]=false;
 }
 if(mx - 2 >= 0)
 {
  if(my - 1 >= 0)s[mx-2][my-1]=false;
  if(my + 1 <= m)s[mx-2][my+1]=false;
 }
 if(mx + 2 <= n)
 {
  if(my - 1 >= 0)s[mx+2][my-1]=false;
  if(my + 1 <= m)s[mx+2][my+1]=false;
 }
}
void go(int x,int y)
{
 if(x+1 <= n && s[x+1][y])go(x+1,y);
 if(y+1 <= m && s[x][y+1])go(x,y+1);
 if(x==n && y==m) k++;
}
int main()
{
 cin >> n >> m >> mx >> my;
 settrue();
 setfalse();
 go(0,0);
 cout << k << endl;
}
