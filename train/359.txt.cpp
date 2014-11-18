#include<iostream>
using namespace std;


int n,m,data[301],f[301][301]={0};

typedef struct tree
{
       int left,right;
};
tree treearray[301];
/////////////////////////////////
int max(int o,int p)
 {return o>p?o:p;}

int treedp(int x,int y)
{int z,c,d;
 if(x==-1)return 0;
 if(y==0)return 0;
 if(f[x][y]!=0)return f[x][y]; 
 f[x][y]=treedp(treearray[x].right,y);
 

for(z=0;z<y;z++)
{c=treedp(treearray[x].left,z);
 d=treedp(treearray[x].right,y-1-z);
 
 f[x][y]=max(f[x][y],data[x]+c+d); 
}
return  f[x][y]; 
        
}



/////////////////////////////////
main()
{int i,j,a,b,z;
 cin>>n>>m;
 
 for(i=1;i<=n;i++)
  {cin>>a>>b;
   data[i]=b;
   treearray[i].right=treearray[a].left;
   treearray[a].left=i;
  }
///////////////////////////////////  
 treearray[0].right=-1; 
 for(i=1;i<=n;i++)
  {if(treearray[i].left==0)treearray[i].left=-1;
   if(treearray[i].right==0)treearray[i].right=-1;
  }
///////////////////////////////////

 
    
    cout<<treedp(0,m+1);
}
   
   
   
