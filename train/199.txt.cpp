#include<iostream>
using namespace std;
__int64 value[33][33],s,temp;
long a[33],root[33][33];
void preorder(int p1,int p2)
{
	if (p2>=p1)
	{
		printf("%ld ",root[p1][p2]);
		preorder(p1,root[p1][p2]-1);
		preorder(root[p1][p2]+1,p2);
	}
}
int main()
{

	long i,j,k,l,n,m,d;
	scanf("%ld",&n);
	memset(value,0,sizeof(value));
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&a[i]);
		value[i][i]=a[i];
		root[i][i]=i;
	}
  //读取n  一个节点是本身就是根节点  一个点构成的二叉树的分就是本身
	for (i=1;i<=n-1;i++)
	{
          value[i][i+1]=a[i]+a[i+1];
		  root[i][i+1]=i;
	}
	//两个节点构成的二叉树就是两个之和  取小的点为根节点
	for (d=2;d<=n-1; d++)//依次构建距离为d的两个节点的最大加分树
	{
		for (i=1;i<=n-d;i++)//从第一个开始 计算从i到i+d的最大加分树
		{
			s=value[i][i]+value[i+1][i+d];//以第一个为根节点 其他的为一个子树
			root[i][i+d]=i;            
			for (j=1;j<=d;j++)
			{
				temp=value[i+j][i+j]+value[i][i+j-1]*value[i+j+1][i+d];//以i+j为根节点 计算加分树
				if (temp>s) {s=temp;root[i][i+d]=i+j;}
			}
			temp=value[i][i+d-1]+value[i+d][i+d];
			if (temp>s) {s=temp; root[i][i+d]=i+d-1;}
			value[i][i+d]=s;
		}
	
	}
	/*for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
    	printf("%I64d   ",value[i][j]);
		printf("\n");
	}*/
		printf("%I64d\n",value[1][n]);
    preorder(1,n);

	return 0;
}
