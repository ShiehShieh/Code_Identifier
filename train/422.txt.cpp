#include<iostream>
using namespace std;

int heliu[15][15];
int i,j,m,n,y,x,k;
int a1,b1,a2,b2;
int step[100][2];
int fx1[2][2]={{0,1},{1,0}};
int sum=0;


int function(int a1=0,int b1=0)
{
    if ( heliu[a1][b1] != 1 && a1 <= n && b1 <= m)
    {
        if (a1 == n && b1 == m) 
            sum++;
        else 
        {
             function(a1+1,b1);
             function(a1,b1+1);
        }
    }
    return sum;
}


int main()
{
 	step[0][0]=0;step[0][1]=0;
 	cin>>n>>m>>y>>x;
 	
 	heliu[y+1][x-2]=1;
 	heliu[y+2][x-1]=1;
 	heliu[y-1][x-2]=1;
 	heliu[y-2][x-1]=1;
 	heliu[y-1][x+2]=1;
 	heliu[y-2][x+1]=1;
 	heliu[y+1][x+2]=1;
 	heliu[y+2][x+1]=1;
 	heliu[y][x]=1;
 	
 	function(0,1);
 	function(1,0);
 	cout<<sum<<endl;
 	return 0;
}
