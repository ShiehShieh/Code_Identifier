#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int tag[26],max,min;
char s[128];
bool prime(int n){
     int i;
     if(n<2)return 0;
     if(n==2)return 1;
     for(i=3;i*i<=n;i+=2)if(n%i==0)return 0;
     return 1;
     }
int main(){
    int i;
    scanf("%s",s);
    memset(tag,0,sizeof(tag));
    for(i=0;s[i]!='\0';i++)tag[s[i]-'a']++;
    max=0,min=128;
    for(i=0;i<26;i++){
        if(tag[i]>max)max=tag[i];
        if(tag[i]<min&&tag[i]>0)min=tag[i];
        }
    if(prime(max-min))printf("Lucky Word\n%d\n",max-min);
    else printf("No Answer\n0\n");
    return 0;
    }

