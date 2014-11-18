#include<iostream>
int n,m;
char cha[30],inp[1000];
char next_permutation(char *s){
	if(s[0]==m-n)return 0;
	int i; 
	for(i=n-1;i>=0;--i)
		if(s[i]+1<s[i+1]||(i==n-1 && s[i]+1<m))
			break;
	++s[i]; 
	for(int j=i+1;j<n;++j)s[j]=s[j-1]+1; 
	return 1;
}
int main(){
	int st,en; 
	scanf("%d%d%d",&st,&en,&n);
	m=en-st+1;
	getchar();
	gets(inp);
	for(int i=0;inp[i];++i)inp[i]-=st+'a'-1;
	int times=5;
	while(times--&&next_permutation(inp)){
		for(int i=0;i<n;++i)	printf("%c",inp[i]+st+'a'-1);
		putchar('\n');
	}
   return 0;
}
