#include<iostream>
using namespace std;
int wa=0,va=0,pa=0;
int N=0,c=1,money=0;
int z[200];
int w[200],v[200],q[200];
int wb[200][3],vb[200][3],qb[200][3];
int u[200],f[200][3000];
int main (){
	cin>>money;
	cin>>N;
	for(int ib=0;ib<=N;ib++){
		for(int jb=0;jb<=2;jb++){
			wb[ib][jb]=vb[ib][jb]=qb[ib][jb]=0;
			}
	}
	for(int ie=0;ie<=N;ie++){
		for(int je=0;je<=money/10;je++){
			f[ie][je]=0;
		}
	}
		for(int s=0;s<=N;s++){z[s]=1;}
	for(int a=1;a<=N;a++){
	cin>>va>>wa>>pa;
    w[a]=v[a]=q[a]=u[a]=0;
	int p=a;
	if(pa==0){
		w[c]=wa;
		v[c]=va/10;
		q[c]=wa*va/10;
		u[c]=p; 
		c++;
	}else{ 
		wb[pa][z[pa]]=wa;
		vb[pa][z[pa]]=va/10;
		qb[pa][z[pa]]=wa*va/10;
		z[pa]++;
	}
	}
	int ma=c-1;
	for(int ia=v[ma];ia<v[ma]+vb[u[ma]][1];ia++){
		f[ma][ia]=q[ma];
	}
	for(int ic=v[ma]+vb[u[ma]][1];ic<v[ma]+vb[u[ma]][1]+vb[u[ma]][2];ic++){
		f[ma][ic]=q[ma]+qb[u[ma]][1];
	}
	for(int id= v[ma]+vb[u[ma]][1]+vb[u[ma]][2];id<=money/10;id++){
		f[ma][id]=q[ma]+qb[u[ma]][1]+qb[u[ma]][2];
	}
	for(int ja=0;ja<v[ma];ja++){
		f[ma][ja]=0;
	}
	for(int i=ma-1;i>=1;i--){
	for(int j=0;j<=money/10;j++){
	f[i][j]=f[i+1][j];
	if(f[i][j]<f[i+1][j-v[i]]+q[i] && j>=v[i]){f[i][j]=f[i+1][j-v[i]]+q[i];}
	if(f[i][j]<f[i+1][j-v[i]-vb[u[i]][1]]+q[i]+qb[u[i]][1] && j>=v[i]+vb[u[i]][1]){f[i][j]=f[i+1][j-v[i]-vb[u[i]][1]]+q[i]+qb[u[i]][1];}
   	if(f[i][j]<f[i+1][j-v[i]-vb[u[i]][2]]+q[i]+qb[u[i]][2] && j>=v[i]+vb[u[i]][2]){f[i][j]=f[i+1][j-v[i]-vb[u[i]][2]]+q[i]+qb[u[i]][2];}
	if(f[i][j]<f[i+1][j-v[i]-vb[u[i]][1]-vb[u[i]][2]]+q[i]+qb[u[i]][1]+qb[u[i]][2] && j>=v[i]+vb[u[i]][2]+vb[u[i]][1]){
		f[i][j]=f[i+1][j-v[i]-vb[u[i]][1]-vb[u[i]][2]]+q[i]+qb[u[i]][1]+qb[u[i]][2];}
		}
	}
	cout<<f[1][money/10]*10<<endl;
	return 0;
}
	


