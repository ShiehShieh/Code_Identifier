#include<iostream>
int main(){
	int u,v,maxi=-1,p=0;
	for(int i=1;i<=7;++i){
		scanf("%d%d",&u,&v);
		if(maxi<u+v&&8<u+v)p=i,maxi=u+v;
	}
	printf("%d\n",p);
   return 0;
}
