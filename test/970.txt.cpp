#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int maxn=10;
const int maxm=10;

bool Join[maxn+1][maxm+1];
bool State[maxn+1][maxm+1],ts[maxn+1][maxm+1];
bool b1[maxn+1],b2[maxn+1],kg[maxn+1];
int n,m;
long ans=0,kgs;

void Init()
{
	int i,j;
	char ch;
	memset(Join,false,sizeof(Join));
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			scanf("%c",&ch);
			if(ch=='0') State[i][j]=false;
			else if(ch=='1') State[i][j]=true;
		}	
		scanf("%c",&ch);
	}
	/*
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++)
		  if(State[i][j]) printf(" 1");
		  else printf(" 0");
		 printf("\n");
	}*/
}

void Change(int col)
{
	int i;
	for(i=1;i<=n;i++) 
	  if(kg[i]) {
	  	kgs++;
        ts[i][col]=!ts[i][col];
	  	ts[i-1][col]=!ts[i-1][col];
	  	ts[i+1][col]=!ts[i+1][col];
	  	ts[i][col-1]=!ts[i][col-1];
	  	ts[i][col+1]=!ts[i][col+1];
	  } 
}

void Show()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		   if(ts[i][j]) printf("1"); else printf("0");
		printf("\n");
	}
	printf("\n");
}

bool Check()
{
	for(int k=2;k<=m;k++) {
	  for(int i=1;i<=n;i++)
	    if(ts[i][k-1]) b2[i]=false;
	    else b2[i]=true;
	  memcpy(kg,b2,sizeof(b2));
	  Change(k);
	  //Show();
	}
	for(int i=1;i<=n;i++)
	  if(ts[i][m]==false) return false;
	if(kgs<ans) ans=kgs;
    return true;		
}

void Dfs1(int depth)
{
	if(depth>n) {
		memcpy(ts,State,sizeof(State));
		memcpy(kg,b1,sizeof(b1));
		kgs=0;
        Change(1);
		//Show();
		Check(); 
		return;
	}
	b1[depth]=true;
	Dfs1(depth+1);
	b1[depth]=false;
	Dfs1(depth+1);	
}

int main()
{
	int kase; char ch;
	scanf("%d",&kase); scanf("%c",&ch);
	while(kase-->0) {
	  n=5; m=5;
      Init();
      if(kase>0) scanf("%c",&ch);
	  ans=100;
	  Dfs1(1);
	  if(ans<=6) printf("%ld\n",ans);
	  else printf("-1\n");
    }
	return 0;
}
