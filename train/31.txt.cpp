#include<stdio.h>
int a[10002]={0},b[10002]={0},len=1;
int zs(int x){
	if(x<2) return(0);
	int i;
	for(i=2;i*i<=x;i++){
		if(x%i==0) return(0);
	}
	return(1);
}
void add(int v,int x){
	int i,j=2;
    i=x;
    while(i>=j){
		if(zs(i)) break;
		while(i%j==0){
			i/=j;
			a[j]+=v;
		}
		j++;
	}
	if(i>1) a[i]+=v;
}
void ad(int x){
	int i,j;
	for(i=1;i<=len;i++){
		b[i]*=x;
	}
	for(i=1;i<=len;i++){
		if(b[i]>=10){
			b[i+1]+=(b[i]/10);
			b[i]%=10;
		}
	}
	len++;
	while(b[len]){
		if(b[len]>=10){
			b[len+1]+=(b[len]/10);
			b[len]%=10;
		}
		len++;
	}
	if(b[len]==0) len--;
}
int main(){
    int n,i,j,x,y;
    for(i=1;i<=10000;i++) a[i]=0;
    for(i=1;i<=10000;i++) b[i]=0;
    scanf("%d %d %d",&n,&x,&y);
    for(i=n+1;i<=n+x;i++){
		add(1,i);
	}
    for(i=2;i<=x;i++){
		add(-1,i);
	}
    for(i=n+1;i<=n+y;i++){
		add(1,i);
	}
    for(i=2;i<=y;i++){
		add(-1,i);
	}
	b[1]=1;
	len=1;
	for(i=2;i<=n+x+y;i++){
		for(j=1;j<=a[i];j++){
			ad(i);
		}
	}
	for(i=len;i>=1;i--){
		printf("%d",b[i]);
	}
	//while(1);
	return(0);
}
