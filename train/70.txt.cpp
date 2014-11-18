# include<iostream>
using namespace std;
int main(){
    int max=0,min=101,s,n=0,i;
    int a[27]={};
    char c[101]={};
    cin>>c;
    for(i=0;i<=strlen(c)-1;i++){
       a[c[i]-'a']++;
    }
    for(i=0;i<=25;i++){
        if(a[i]<min&&a[i]>0)min=a[i];
        if(a[i]>max)max=a[i];
    }
    
    s=max-min;
   
    for(i=1;i<=s;i++){
        if(s%i==0){
           n++;
           
           }
    }
    if(n==2)cout<<"Lucky Word"<<endl<<s<<endl;
    else cout<<"No Answer"<<endl<<'0'<<endl;

    return 0;
}

