#include<stdio.h>
#include<string.h>
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    char s[1000],wh[10];
    int i,j;
    gets(wh);
    scanf("\n");
    printf("%s",wh);
    gets(s);
    if(s[0]>='A'&&s[0]<='Z') s[0]+=32;
    for(i=2;i<strlen(s);i++){
        if(s[i-2]==' '&&s[i-1]=='i'&&s[i]=='s'&&s[i+1]==' ') break;
    }
    for(j=i+1;j<strlen(s)-1;j++) printf("%c",s[j]);
    printf(" ");
    for(j=0;j<=i;j++) printf("%c",s[j]);
    printf("!");
}

