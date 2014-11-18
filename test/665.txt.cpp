#include <stdio.h>
#include <string.h>
int n,len;
char s[300];
void h1(){
     int i;
     printf(" ");
     for (i=1;i<=n;i++) printf("-");
     printf(" ");
}
void h0(){
     for (int i=0;i<=n+1;i++) printf(" ");
}
void sl(){
     printf("|");
     for (int i=0;i<=n;i++) printf(" ");
}
void sr(){
     for (int i=0;i<=n;i++) printf(" ");
     printf("|");
}
void slr(){
     printf("|");
     for (int i=0;i<n;i++) printf(" ");
     printf("|");
}
int main(){
    int i,j,k;
    //freopen("p1064out.txt","w",stdout);
    scanf("%d\n",&n);
    gets(s);len=strlen(s);
    for (j=0;j<len;j++){
        switch (s[j]){
               case '1':case '4':h0();break;
               default:h1();
        }
        if(j!=len-1) printf(" ");
    }
    printf("\n");
    for (i=1;i<=n;i++){
        for (j=0;j<len;j++){
            switch (s[j]){
                   case '4':case '8':case '9':case '0':slr();break;
                   case '1':case '2':case '3':case '7':sr();break;
                   default:sl();
            }
            if(j!=len-1) printf(" ");
        }
        printf("\n");
    }
    for (j=0;j<len;j++){
        switch (s[j]){
               case '1':case '7':case '0':h0();break;
               default:h1();
        }
        if(j!=len-1) printf(" ");
    }
    printf("\n");
    for (i=1;i<=n;i++){
        for (j=0;j<len;j++){
            switch (s[j]){
                   case '6':case '8':case '0':slr();break;
                   case '1':case '4':case '3':case '7':case '5':case '9':sr();break;
                   default:sl();
            }
            if(j!=len-1) printf(" ");
        }
        printf("\n");
    }
    for (j=0;j<len;j++){
        switch (s[j]){
               case '1':case '7':case '4':h0();break;
               default:h1();
        }
        if(j!=len-1) printf(" ");
    }
    return 0;
}

