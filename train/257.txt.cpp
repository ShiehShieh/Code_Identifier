
#include <queue>
#include <algorithm>
using namespace std;

struct cmp{
    bool operator ()(const int &a,const int &b){
        return a > b;
     }
};

int main()
{
#ifndef ONLINE_JUDGE
 //   freopen("_in.txt", "r", stdin); freopen("_out.txt", "w", stdout);
#endif
    int n;
    int i;
    int num;
    int a, b, ans;
    priority_queue<int, vector<int>, cmp>  Q;
    
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &num);
        Q.push(num);
    }
    
    ans = 0;
    while (!Q.empty()) {
        a = Q.top();    Q.pop();
        if (Q.empty()) break;
        b = Q.top();    Q.pop();
        ans += a + b;
        Q.push(a + b);
    }
    
    printf("%d\n", ans);
    return 0;
}

