#include <iostream>
using namespace std;
#define MAX_INT 2000000000
#define PR(A)  cout<<#A<<": "<<A<<endl;
typedef struct s_node{
int num;
int fee;
int s_count;
int sons[1501];
}t_node;
t_node nodes[1501];
int f[1501][3];
int minx2(int a, int b){
return a<=b?a:b;
}
int minx3(int a, int b, int c){
int x = minx2(a, b);
int y = minx2(b, c);
return x<=y?x:y;
}
void dp(int i){
int j,temp=MAX_INT;
if(nodes[i].s_count == 0){
f[i][0] = nodes[i].fee;
f[i][1] = nodes[i].fee;
return;
}
f[i][0] = nodes[i].fee;
f[i][2] = f[i][1] = 0;
for(j=1;j<=nodes[i].s_count;j++){
dp(nodes[i].sons[j]); 
f[i][0] += minx3(f[nodes[i].sons[j]][0],
f[nodes[i].sons[j]][1], f[nodes[i].sons[j]][2]);
f[i][1] += minx2(f[nodes[i].sons[j]][0],
f[nodes[i].sons[j]][1]);
if(temp > f[nodes[i].sons[j]][0] -
minx2(f[nodes[i].sons[j]][0], f[nodes[i].sons[j]][1]))
temp = f[nodes[i].sons[j]][0] -
minx2(f[nodes[i].sons[j]][0], f[nodes[i].sons[j]][1]);
f[i][2] += f[nodes[i].sons[j]][1];
}
f[i][1] += temp;
}
int main(int argc, char* args[]){
int i,j,n,r=0,root=0,p; 
cin>>n;
for(i=1;i<=n;i++){
cin>>p;
r+=p;
nodes[p].num = p;
cin>>nodes[p].fee;
cin>>nodes[p].s_count;
for(j=1;j<=nodes[p].s_count;j++){
cin>>nodes[p].sons[j];
root+=nodes[p].sons[j];
}
}
root = r-root;
dp(root);
if(nodes[root].s_count!=0)
cout<<minx2(f[root][0], f[root][1])<<endl;
else
cout<<f[root][1]<<endl;
return 0;
} 

