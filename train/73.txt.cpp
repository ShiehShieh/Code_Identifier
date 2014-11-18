#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N,M,map[128][128],lnk[128],tag[128];
int seek(int k){
    int i,tmp;
    for(i=1;i<=M;i++)
        if(!tag[i]&&map[k][i]){
            tag[i]=1;
            tmp=lnk[i];
            lnk[i]=k;
            if(!tmp||seek(tmp))return 1;
            lnk[i]=tmp;
            }
    return 0;
    }
int main(){
    int i,j,ans;
    char s[128];
    scanf("%d %d",&N,&M);
    for(i=1;i<=N;i++){
        scanf("%s",s);
        for(j=1;j<=M;j++)
            map[i][j]=s[j-1]-'0';
        }
    memset(lnk,0,sizeof(lnk));
    for(i=1,ans=0;i<=N;i++){
         memset(tag,0,sizeof(tag));
         if(seek(i))ans++;
         }
    printf("%d\n",ans);
    return 0;
    }
