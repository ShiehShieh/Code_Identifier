#include <iostream>
using namespace std;
const int oi[10][6]={{0},{1,2,4,5},{1,2,3},{2,3,5,6},{1,4,7},{2,4,5,6,8},{3,6,9},{4,5,7,8},{7,8,9},{5,6,8,9}};
int way[30]={1},ans[30],a[10],use[10],mini=30;
void work(int w)
{
    int i;
    for(i=0;i<=4&&oi[i];i++){
        a[oi[w][i]]++;
        a[oi[w][i]]%=4;
    }
}
bool check()
{
    for(int i=1;i<=9;i++)
        if(a[i]!=0) return false;
    return true;
}
void dfs(int step)
{
    if(mini<step-1) return;
    if(check()){
        if(step-1<mini){
            mini=step-1;
            for(int j=1;j<=mini;j++)
                ans[j]=way[j];
        }
        return;
    }
    for(int i=way[step-1];i<=9;i++){
        if(use[i]>=3) continue;
        work(i);
        way[step]=i;
        use[i]++;
        dfs(step+1);
        for(int k=1;k<=3;k++)
            work(i);
        use[i]--;
    }
}
int main()
{
    for(int i=1;i<=9;i++)
        cin>>a[i];
    dfs(1);
    for(int i=1;i<mini;i++)
        cout<<ans[i]<<' ';
    cout<<ans[mini]<<endl;
    return 0;
}
