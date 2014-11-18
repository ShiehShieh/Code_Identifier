#define K -11
#include<iostream>
#include<string.h>
using namespace std;

int nu[99],p=0,q=0;char si[99],w;
int s,c;

int zh( char p )
{
    if ( p == '+' || p == '-' ) return 1;
    if ( p == '*' || p == '/' ) return 2;
    if ( p == '\n'|| p == ')' ) return 0;
    if ( p == '~' ) return -2;
    if ( p == '^' ) return 3;
    if ( p == '[' ) return -1;
}

int dengjia(void)
{
    p=0;q=0;
    int k,o,num[99];
    int i=0,j=0,l;
    char r,sig[99];
    sig[0]='~';num[0]=nu[p++];r=si[q++];
    while ( r == '(' ) {sig[++j]='[';r=si[q++];}
    while ( r != '\n' )
    { 
         if ( r != ')' ) k=nu[p++]; 
         while ( r == '(' ) {sig[++j]='[';r=si[q++];}
         if ( r == '\n' ) break;
         while (  zh(r) <= zh(sig[j]) )
         {
             if ( sig[j] == '+' )
             {
                  num[i-1]=num[i-1]+num[i];num[i-1]%=10000;
             }
             if ( sig[j] == '-' ) 
             {
                  num[i-1]=num[i-1]-num[i];num[i-1]%=10000;
             }
             if ( sig[j] == '*' ) 
             {
                  num[i-1]=num[i-1]*num[i];num[i-1]%=10000;
             }
             if ( sig[j] == '^' ) 
             {    
                  o=num[i-1];
                  for ( l = 2 ; l <= num[i] ; ++ l )
                  { 
                       num[i-1]*=o;num[i-1]%=10000;
                  }
                  num[i-1]%=10000;
             }
             i--;j--;
         }
         if ( r == ')' && sig[j] == '[' )
         {
             j--;r=si[q++];if ( r == '\n' ) break;
         }
         else
         {
             sig[++j]=r;num[++i]=k;r=si[q++];
         } 
    }
    while (  zh(r) <= zh(sig[j]) )
    {
         if ( sig[j] == '+' ) 
         {
              num[i-1]=num[i-1]+num[i];num[i-1]%=10000;
         }
         if ( sig[j] == '-' ) 
         {
              num[i-1]=num[i-1]-num[i];num[i-1]%=10000;
         }
         if ( sig[j] == '*' )
         {
              num[i-1]=num[i-1]*num[i];num[i-1]%=10000;
         }
         if ( sig[j] == '^' ) 
         {    
              o=num[i-1];
              for ( l = 2 ; l <= num[i] ; ++ l )
              {
                   
                  num[i-1]*=o;num[i-1]%=10000;
              }
              num[i-1]%=10000;
         }
         i--;j--;
    }
    return (num[0]);
}

void dushu()
{ 
    char a[99]={'\0'},b;
    int i,j,k,len;
    scanf("%c",&b);
    while (  b == '\n' ) 
          scanf("%c",&b);
    a[0]=b;
    for ( k = 0 ; a[k] != '\n' ; ++ k ) 
        scanf("%c",&a[k+1]);
    len=k;i=j=k=0;
    while ( k < len )
    {
        if ( a[k] >= 48 && a[k] <= 57 )
        {
            while ( a[k] >= '0' && a[k] <= '9' )
            {
                 nu[i]*=10;
                 nu[i]=nu[i]+a[k]-'0';
                 k++;
            }
            if ( a[k-2] == '-' && k < 3 ) nu[i]*=-1;
            i++;
        }
        else 
        {
            if ( a[k] == 'a' )
            {
                 nu[i++]=K;k++;
            }
            else
            {
                 if ( a[k] != ' ' ) 
                 {
                       if ( k == 0 && a[k] == '-' ) k++;
                       else si[j++]=a[k++];
                 }
                 else k++;
            }
        }
    }                            
    si[j]='\n';
}

int main()
{
    int n,m,w,g=0;
    int shushu[26];
    memset( nu , 0 , sizeof ( int ) *99 );
    dushu();
    w=dengjia();
    scanf("%d",&n);
    memset( shushu , 0 , sizeof( int ) *26 );
    for ( m = 0 ; m < n ; ++ m )
    {
        memset( nu , 0 , sizeof ( int ) *99 );
        dushu();
        if ( w == dengjia() ) shushu[g++]=m+65;
    }
    for ( n = 0 ; n < g ; ++ n ) 
        printf("%c",shushu[n]);
    printf("\n");
}
