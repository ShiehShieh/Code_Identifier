#include<iostream.h>
#include<string.h>
int main(){ 
    int max=0;
    int i,j,k,w,o,l,z;
    char a[100],b,c,e[100];
    cin>>o;
    z=0; 
    for (k=1;k<=o;k++){
        l=0;
        cin>>a>>i>>j>>b>>c>>w;
        if (i>80&&w>=1) l+=8000;
        if (i>85&&j>80) l+=4000;
        if (i>90) l+=2000;
        if (i>85 &&c=='Y') l+=1000;        
        if (j>80 &&b=='Y') l+=850;
        if (l>max) {max=l; strcpy(e,a); }
        z+=l; 
    }
    cout <<e<<endl<<max<<endl<<z<<endl;
    return 0;
}
