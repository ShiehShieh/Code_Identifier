#include<iostream>
using namespace std;
long c[2000][2000];
long n;
int lowbit(long ii)
{
	return ii&(ii^(ii-1));
}


void chang(long i,long j,long k)
{
	long tempj;
	
	while(i<=n)
	{
		tempj=j;
		while (tempj<=n)
		{
			c[i][tempj]+=k;     tempj+=lowbit(tempj);
		}
		i+=lowbit(i);		
	}
}

long getsum(long i,long j)
{
	long tempj,result=0;
	while (i>0)
	{
	tempj=j;
	while (tempj>0)
	{
      result=result+c[i][tempj];
	  tempj-=lowbit(tempj);
	}
	i=i-lowbit(i);
}
return result;   
 
}



int main()
{
	long i,j,k,l,m,ans,x,y,x1,y1,x2,y2;
	scanf("%ld",&n);
	scanf("%ld",&m);
	memset(c,0,sizeof(c));
	while (m!=3)
	{
		if (m==1) {
			 scanf("%ld%ld%ld",&x,&y,&k);
			 x++;  y++;  chang(x,y,k);
		/*	for (i=0;i<=n;i++)
				 for (j=0;j<=n;j++)
				 {
					 if (c[i][j]!=0) printf("%ld  %ld %ld\n ",c[i][j],i,j);
				 }*/
			
		}
		else if(m==2)
		{
			ans=0;
			scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);
			x1++;y1++;y2++;x2++;
              ans=getsum(x2,y2);
			  //	printf("%ld\n",ans);
			if (x1>1)ans-=getsum(x1-1,y2);
			if (y1>1)  ans-=getsum(x2,y1-1);
			if (x1>1 && y1>1)ans+=getsum(x1-1,y1-1);
			printf("%ld\n",ans);
		}
			scanf("%ld",&m);

	}
	return 0;
}
/*
4
1 0 0 5
1 1 1 5
2 0 0 1 1
*/
