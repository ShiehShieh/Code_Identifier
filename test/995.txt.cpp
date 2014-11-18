#include<stdio.h>
int a[100000][2],n,m;
int lowbit(int x){
    return(x&(x^(x-1)));
}
void insert(int x,int y){
    int i;
    for(i=x;i<=n;i+=lowbit(i)){
        a[i][y]++;
    }
}
int find(int x,int y){
    int i,sum=0;
    for(i=x;i>0;i-=lowbit(i)){
        sum+=a[i][y];
    }
    return(sum);
}
int work(){
    int i,j,p,x,y,t,count;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&p,&x,&y);
        if(p==1){
            insert(x,0);
            insert(y,1);
        }
        else{
            t=find(y,0)-find(x-1,1);
            printf("%d",t);
        }
    }
}
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    work();
}

