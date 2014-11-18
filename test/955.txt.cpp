#include<iostream>
#define MAXNUM 500
const char gra[8][8]={"+---+  ","|   |/ ","|   | +","+---+ |"," /   /|","  +---+"};
const int rg[8][2]={{0,5},{0,6},{0,7},{0,7},{1,7},{2,7}};
int lvx=0,lvy=0;
char sp[MAXNUM][MAXNUM]={};
int n,m,hner[MAXNUM][MAXNUM]={};
inline int Xloc(int h,int i,int j){return 3*h+2*(n-i-1);}
inline int Yloc(int h,int i,int j){return 4*j+2*(n-i-1);}
void fill(int x,int y){
	for(int i=0;i<6;++i)
		for(int j=rg[i][0];j<rg[i][1];++j)
			sp[x+i][y+j]=gra[i][j],
			lvx>?=x+i+1,lvy>?=y+j+1;
}
int main(){
	int high=0;
	n=m=200; 
	for(int i=0;i<n;++i)for(int j=0;j<m;++j)sp[i][j]='.';
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&hner[i][j]),high>?=gra[i][j];
	for(int h=0;h<high;++h)
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(hner[i][j]){
					--hner[i][j];
					fill(Xloc(h,i,j),Yloc(h,i,j));
				}
	for(int i=lvx-1;i>=0;--i){
		for(int j=0;j<lvy;++j)
			putchar(sp[i][j]);
		putchar('\n');
	}
   return 0;
}
