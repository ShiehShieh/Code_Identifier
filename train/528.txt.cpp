#include<iostream>
using namespace std;
int main(){
	int i=0,j=0,k=0,n=0,t=0;
	 int best=0;
	int f[200][200];
	int wei[200],top[200];
	cin>>n;
	for(t=1;t<=n;t++){
		cin>>top[t];
		if(t>1){
			wei[t-1]=top[t];
		}
	}
	wei[n]=top[1];
	for(k=n+1;k<=2*n-1;k++){
		top[k]=top[k-n];
		wei[k]=wei[k-n];
	}
	for(int y=1;y<=2*n;y++){
		for(int g=1;g<=2*n;g++){
		f[y][g]=0;
		}
	}
	
	for(int p=1;p<=n-1;p++)
	for(i=1;i<=2*n-2;i++){
	j=i+p;
	if(j>2*n-1){
	break;
	}
	for(k=i;k<=j-1;k++){
		 if(f[i][j]<f[i][k]+f[k+1][j]+top[i]*wei[k]*wei[j]){
    f[i][j]=f[i][k]+f[k+1][j]+top[i]*wei[k]*wei[j];
		 }
	}
	} best=0;
	for(int h=1;h<=n;h++){
	
		if(best<f[h][h+n-1]){
			best=f[h][h+n-1];
		}
	}
	cout<<best<<endl;
	return 0;
}
