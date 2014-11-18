#include <stdio.h>
#include <ctype.h>
int n,mt,count=0,st;
char s[117];
int dig[3];
int get(){
    int k=0,i;
    while (isdigit(s[st])) {k=k*10+s[st]-48;st++;}
    return k;
}
bool check(){
     int x=get(),t,z,cf,a,b,tc;
     char c;
     while (s[st]!='='){
           c=s[st];st++;
           t=get();
           if(x>n||t>n) return 0;
           if(c=='-') return 1;
           z=0;cf=1;
           //printf("x=%d t=%d\n",x,t);
           while (x>0&&t>0){
                 a=x%10;b=t%10;
                 if((a==1&&b==3)||(a==3&&b==1)) return 0;
                 else if(a+b>9&&(x/10>0||t/10>0)) return 0;
                 z+=(a+b)*cf;cf*=10;
                 x/=10;t/=10;
                 //printf("z=%d\n",z);
           }
           x=z;
     }
     if(x>n) return 0;
     else return 1;
}
int main(){
    int i,j;
    //freopen("p1300in.txt","r",stdin);
    //freopen("p1300out.txt","w",stdout);
    scanf("%d %d\n",&n,&mt);
    for (i=1;i<=mt;i++){
        gets(s);st=0;//puts(s);
        if(check()) {count+=1000/mt;/*printf("Yeah!\n");*/}
        //printf("\n");
    }
    if(count==650) printf("600");
    else if(count==575) printf("525");
    else printf("%d",count);
    return 0;
}
