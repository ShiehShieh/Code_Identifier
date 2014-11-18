#include <iostream>
#include <cstdlib>
#define MOD 10000
using namespace std;
char sin[100],stack[100];
int n,ts,td,istack[100];
bool isok[27];
struct node{
char opt;
int flag,num;
} d[27][100];
void getexp(int x){
int i=-1,k;
ts=td=0;
while(sin[++i])
switch(sin[i]){
case '0': case '1': case'2': case'3': case '4': case '5': case'6': case'7': case '8': case '9':
k=0;
while(sin[i+1]>='0' && sin[i+1]<='9')
(k*=10)+=sin[i++]-'0';
d[x][++td].flag=1;
d[x][td].num=k*10+sin[i]-'0';
break;
case 'a':
d[x][++td].flag=2; d[x][td].opt='a';
break;
case '(':
stack[++ts]='(';
break;
case ')':
while(ts>0 && stack[ts]!='('){
d[x][++td].flag=3; d[x][td].opt=stack[ts--];
}
--ts;
break;
case '+':case '-':
while(ts>0 && stack[ts]!='('){
d[x][++td].flag=3; d[x][td].opt=stack[ts--];
}
stack[++ts]=sin[i];
break;
case '*':
while(ts>0 &&(stack[ts]=='*' || stack[ts]=='^')){
d[x][++td].flag=3; d[x][td].opt=stack[ts--];
}
stack[++ts]='*';
break;
case '^':
while(ts>0 && stack[ts]=='^'){
d[x][++td].flag=3; d[x][td].opt=stack[ts--];
}
stack[++ts]='^';
break;
}
while(ts>0){
d[x][++td].flag=3; d[x][td].opt=stack[ts--];
}
}

int getres(int x1,int x2,char opt){
int i,r;
switch(opt){
case '+': r=(x1+x2)%MOD; break;
case '-': r=(x1-x2)%MOD; break;
case '*': r=(x1*x2)%MOD; break;
case '^':
r=1;
for(i=1;i<=x2;++i)
r=(r*x1)%MOD;
break;
}
return r;
}

int calc(int k,int x){
int i=0,x1,x2;
ts=td=0;
while(d[k][++i].flag)
switch(d[k][i].flag){
case 1:istack[++ts]=d[k][i].num; break;
case 2:istack[++ts]=x;break;
case 3:
x2=istack[ts--]; x1=istack[ts--];
istack[++ts]=getres(x1,x2,d[k][i].opt);
break;
}
return (istack[ts]+MOD)%MOD;
}
int main(){
int i,j,x,ans0,ans;
memset(isok,true,sizeof(isok));
cin.getline(sin,100);
getexp(0);
cin>>n;
cin.getline(sin,100);
for(i=1;i<=n;++i){
cin.getline(sin,100);
getexp(i);
}
for(i=0;i<=10;++i){
x=rand()%MOD;
ans0=calc(0,x);
for(j=1;j<=n;++j)
if(isok[j] && ans0!=calc(j,x))
isok[j]=false;
}
for(i=1;i<=n;++i)
if(isok[i])
cout<<(char)('A'-1+i);
cout<<endl;
return 0;
}

