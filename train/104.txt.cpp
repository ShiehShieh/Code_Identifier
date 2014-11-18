#include <stdio.h>
int r,c,count=0;
bool map[1001][1001];
char s[1005];
int fx(int x,int y){
    int i=y;
    while (map[x][i]) i++;
    return i-1;
}
int fy(int x,int y){
    int i=x;
    while (map[i][y]) i++;
    return i-1;
}
void fill(int x1,int y1,int x2,int y2){
     for (int i=x1;i<=x2;i++) for (int j=y1;j<=y2;j++) map[i][j]=0;
}
int main(){
    //freopen("p1076in.txt","r",stdin);
    //freopen("p1076out.txt","w",stdout);
    int i,j,x,y,i2,j2;
    bool flag;
    scanf("%d %d\n",&r,&c);
    for (i=1;i<=r;i++){
        gets(s);
        for (j=1;j<=c;j++) map[i][j]=(s[j-1]=='.')?0:1;
    }
    for (i=1;i<=r;i++)
        for (j=1;j<=c;j++){
            if(!map[i][j]) continue;
            flag=0;
            y=fx(i,j);x=fy(i,j);
            for (i2=i;i2<=x;i2++){
                for (j2=j;j2<=y;j2++) if(!map[i2][j2]) {flag=1;/*printf("1");*/break;}
                if(j2<=y) break;
            }
            //printf("i=%d j=%d x=%d y=%d\n",i,j,x,y);
            if(!flag) for (i2=i;i2<=x;i2++) if(map[i2][j-1]||map[i2][y+1]) {flag=1;/*printf("2");*/break;}
            if(!flag) for (j2=j;j2<=y;j2++) if(map[i-1][j2]||map[x+1][j2]) {flag=1;/*printf("3");*/break;}
            if(flag) {printf("Bad placement.");return 0;}
            else {count++;fill(i,j,x,y);}
        }
    printf("There are %d ships.",count);
    return 0;
}

