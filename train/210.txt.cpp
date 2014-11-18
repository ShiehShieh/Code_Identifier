#include<iostream>
#include<string>
using namespace std;
int main(){
    int p,k,i,j,n,x,g[300][300],f[300][300],max;
    bool last[3000];
    char word[500],T[1000],s[10][500];
    cin>>p>>k;
    cin.getline(T,21);
    for(i=0;i<p;i++){
       cin.getline(T,21);
       for(j=0;j<20;j++)word[j+20*i]=T[j];
    }
    cin>>n;
    for(i=0;i<n;i++){
    cin>>s[i];
    for(j=0;j<i;j++){
    if(strstr(s[i],s[j])==s[i])
    break;
    else if(strstr(s[j],s[i])==s[j]){
    for(x=0;x<=strlen(s[i]);x++)
    s[j][x]=s[i][x];
    }
    }
    if(j!=i){i--;n--;}
    }
    for(i=0;i<n;i++){
       int min=i;
       for(j=i;j<n;j++)
          if(strlen(s[j])<strlen(s[min]))min=j;
    for(j=0;j<=strlen(s[min]);j++)
    T[j]=s[min][j];
    for(j=0;j<=strlen(s[i]);j++)s[min][j]=s[i][j];
    for(j=0;j<=strlen(T);j++)s[i][j]=T[j];
    }
    int len=strlen(word);
    for(i=0;i<len;i++){
       int t=0;
       for(j=0;j<len;j++)last[j]=false;
       T[t++]=word[i];
       T[t]='\0';
       for(j=0;j<n;j++)
          if(strstr(T,s[j])!=NULL){
             g[i][i]=1;
             last[0]=true;
             break;
          }
          for(j=i+1;j<len;j++){
             g[i][j]=g[i][j-1];
             T[t++]=word[j];
             T[t]='\0';
             for(x=0;x<n;x++){
                if((last[(strlen(T)-strlen(s[x]))]==false) && (strstr((T+(strlen(T)-strlen(s[x]))),s[x])!=NULL)){
                   last[(strlen(T)-strlen(s[x]))]=true;
                   g[i][j]++;
                }
             }
          }
       }

    for(i=0;i<len;i++)f[i][0]=g[i][len-1];
    for(i=1;i<k;i++)
       for(j=0;j<len-i;j++){
          max=0;
          for(x=j;x<len-i;x++)
             if(max<(p=g[j][x]+f[x+1][i-1]))max=p;
          f[j][i]=max;
    }
    cout<<f[0][k-1];
    return 0;
}

