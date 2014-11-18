#include<iostream>
#include<string>
#include<cctype>
#define MAXN 5001
#define INO void
using namespace std;
int father[MAXN],n,m,p;
string name[MAXN];
int getfather(int v){
    if (father[v]==v)
    return v;
    father[v]=getfather(father[v]);
    return father[v];
}
bool same(int x,int y){
     return (getfather(x)==getfather(y));
}
INO judge(int x,int y){
    int fx,fy;
    fx=getfather(x);
    fy=getfather(y);
    if (fx==fy) return ;
    father[fx]=fy;
}
INO init(){
    cin>>n>>m>>p;
    for (int i=1;i<=n;i++)
    father[i]=i;
}
int main (void){
    init();
    int a,b;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        judge(a,b);
        }
    for (int i=0;i<p;i++){
        if (i!=0) cout<<endl;
        cin>>a>>b;
        if (same(a,b))
        cout<<"Yes";
        else cout<<"No";
        }
        return 0;
}

