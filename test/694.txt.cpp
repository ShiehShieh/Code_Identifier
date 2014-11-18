#include<iostream>
int a[2][2]={};
char ban;
inline char mec(char cs){return ('0'<=cs&&cs<='9')?0:(cs=='+'?1:(cs=='-'?2:('a'<=cs&&cs<='z'?3:4)));}
void strano(int &p,int &q){
	char c,pre='+';
	int tmp=1;
	while((c=getchar())!=EOF && c!='=' && c!='\n'){
		if(mec(c)==3)ban=c,p+=tmp,tmp=1;
		else if(mec(c)==2){
			if(mec(pre)==0)q+=tmp,tmp=1;
			tmp*=-1;
		}
		else if(mec(c)==1 && mec(pre)==0)q+=tmp,tmp=1;
		else if(mec(c)==0){
			if(mec(pre)==0)tmp=tmp*10+(tmp>0?1:-1)*(c-'0');
			else tmp=(tmp>0?1:-1)*(c-'0');
		}
		if(mec(c)!=4)pre=c;
	}
	if(mec(pre)==0)q+=tmp,tmp=1;
}
int main(){
	strano(a[0][0],a[0][1]);
	strano(a[1][0],a[1][1]);
	//printf("%d %d = %d %d\n",a[0][0],a[0][1],a[1][0],a[1][1]);
	printf("%c=%.3lf\n",ban,(double)(a[0][1]-a[1][1])/(double)(a[1][0]-a[0][0]));
   return 0;
}
