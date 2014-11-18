#include<stdio.h>
#include<string>
#define max(a,b) a>b?a:b
using namespace std;
long n,r,c,ins[502][502],map[502][502],opin;
int work(int i,int j){
    if(map[i][j]==0){
       if(ins[i+1][j]<ins[i][j]) map[i][j]=max(work(i+1,j),map[i][j]);
       if(ins[i][j+1]<ins[i][j]) map[i][j]=max(work(i,j+1),map[i][j]);
       if(ins[i-1][j]<ins[i][j]) map[i][j]=max(work(i-1,j),map[i][j]);
       if(ins[i][j-1]<ins[i][j]) map[i][j]=max(work(i,j-1),map[i][j]);
       map[i][j]++;
       }
    return map[i][j];
}
int main(){
     int w,h,v;
     scanf("%d%d",&r,&c);
     for(h=1;h<=r;h++) for(w=1;w<=c;w++) scanf("%ld",&ins[h][w]);
     for(h=1;h<=r;h++) ins[h][0]=ins[h][c+1]=100000;
     for(w=1;w<=c;w++) ins[0][w]=ins[r+1][w]=100000;
     memset(map,0,sizeof(map));
     opin=1;
     for(h=1;h<=r;h++)
         for(w=1;w<=c;w++)
             if(map[h][w]==0){
                              v=work(h,w);
                              opin=max(opin,v);
                              }
     printf("%ld",opin);
     return 0;
     }

