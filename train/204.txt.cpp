#include <iostream>
#include <cstdlib>
using namespace std;
struct In
{
  int m_x,m_y,s_x,s_y,in,fa;
}tmp,s,T,q[2000000];
int ans,ff,ee,i,n,m,j,x,fx[5],fy[5];
bool t[30][30][5],trap[30][30],hash[1500000];
char c;
void out(int i)
{
  if ( q[i].fa==0 ) return;
  out(q[i].fa);
  ans++;
  if ( q[i].m_x<q[q[i].fa].m_x ) printf("up\n");
  else if ( q[i].m_x>q[q[i].fa].m_x ) printf("down\n");
  else if ( q[i].m_y<q[q[i].fa].m_y ) printf("left\n");
  else if ( q[i].m_y>q[q[i].fa].m_y ) printf("right\n");
  return;
}
bool Hash()
{
  int tmp = (((s.in*6+6+s.m_x)*30+s.m_y)*30+s.s_x)*30+s.s_y;
  if ( hash[tmp] ) return 0;
  hash[tmp] = 1;
  return 1;
}
int main()
{
  cin >> n >> m;
  memset(t,true,sizeof(t));
  fx[1] = -1; fy[1] = 0;  // 4
  fx[2] = 0; fy[2] = -1;  // 1
  fx[3] = 0; fy[3] = 1;   // 3
  fx[4] = 1; fy[4] = 0;   // 2
  for (i=1;i<=n;i++)
   for (j=1;j<=m;j++)
   {
     scanf("%d",&x);
     if ( x&1 ) t[i][j][1] = 0;
     if ( x&2 ) t[i][j][2] = 0;
     if ( x&4 ) t[i][j][3] = 0;
     if ( x&8 ) t[i][j][4] = 0;
   }
  for (i=1;i<=n;i++)
  {
    scanf("\n");
    for (j=1;j<=m;j++)
    {
      scanf("%c",&c);
      if ( c=='E' )
      {
        T.m_x = i;
        T.m_y = j;
      }
      else if ( c=='W' ) trap[i][j] = 1;
      else if ( c=='S' )
      {
        s.m_x = i;
        s.m_y = j;
      }
      else if ( c=='M' )
      {
        s.s_x = i;
        s.s_y = j;
      }
    }
  }
  q[1] = s;
  ff = 1;
  ee = 1;
  while (ff<=ee)
  {
    tmp = q[ff];
    for (i=1;i<=4;i++)
    if ( t[tmp.m_x][tmp.m_y][i] )
    {
      s = tmp;
      s.m_x += fx[i];
      s.m_y += fy[i];
      if ( s.m_x<1 || s.m_x>n || s.m_y<1 || s.m_y>m ) continue;
      if ( trap[s.m_x][s.m_y] ) continue;
      if ( s.s_x==s.m_x && s.s_y==s.m_y ) continue;
      if ( s.m_x==T.m_x && s.m_y==T.m_y )
      {
        s.fa = ff;
        ee++;
        q[ee] = s;
        out(ee);
        printf("total steps: %d\n",ans);
        return 0;
      }
      if ( s.in<=0 )
      {
        if ( s.m_y>s.s_y && t[s.s_x][s.s_y][3] )
        {
          s.s_y++;
          s.in = -1;
          if ( trap[s.s_x][s.s_y] && s.in==-1 ) s.in = 3;
          else if ( s.m_y>s.s_y && t[s.s_x][s.s_y][3] ) s.s_y++;
          else if ( s.m_x>s.s_x && t[s.s_x][s.s_y][4] ) s.s_x++;
          else if ( s.m_x<s.s_x && t[s.s_x][s.s_y][1] ) s.s_x--;
        }
        else if ( s.m_y<s.s_y && t[s.s_x][s.s_y][2] )
        {
          s.s_y--;
          s.in = -1;
          if ( trap[s.s_x][s.s_y] && s.in==-1 ) s.in = 3;
          else if ( s.m_y<s.s_y && t[s.s_x][s.s_y][2] ) s.s_y--;
          else if ( s.m_x>s.s_x && t[s.s_x][s.s_y][4] ) s.s_x++;
          else if ( s.m_x<s.s_x && t[s.s_x][s.s_y][1] ) s.s_x--;
        }
        else if ( s.m_x>s.s_x && t[s.s_x][s.s_y][4] )
        {
          s.s_x++;
          s.in = -1;
          if ( trap[s.s_x][s.s_y] && s.in==-1 ) s.in = 3;
          else if ( s.m_y>s.s_y && t[s.s_x][s.s_y][3] ) s.s_y++;
          else if ( s.m_y<s.s_y && t[s.s_x][s.s_y][2] ) s.s_y--;
          else if ( s.m_x>s.s_x && t[s.s_x][s.s_y][4] ) s.s_x++;
        }
        else if ( s.m_x<s.s_x && t[s.s_x][s.s_y][1] )
        {
          s.s_x--;
          s.in = -1;
          if ( trap[s.s_x][s.s_y] && s.in==-1 ) s.in = 3;
          else if ( s.m_y>s.s_y && t[s.s_x][s.s_y][3] ) s.s_y++;
          else if ( s.m_y<s.s_y && t[s.s_x][s.s_y][2] ) s.s_y--;
          else if ( s.m_x<s.s_x && t[s.s_x][s.s_y][1] ) s.s_x--;
        }
      }else s.in--;
      if ( trap[s.s_x][s.s_y] && s.in==-1 ) s.in = 3;
      if ( (s.s_x!=s.m_x || s.s_y!=s.m_y) && Hash() )
      {
        s.fa = ff;
        ee++;
        q[ee] = s;
      }
    }
    ff++;
  }
  printf("impossible\n");
  return 0;
}

