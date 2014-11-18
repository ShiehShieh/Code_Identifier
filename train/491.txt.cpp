#include<iostream>
#include<string>
using namespace std;
int dp[2001];
string s[2001];

bool check(int a, int b) {
    int len = s[a].length();
    string tmp = s[b].substr(0, len);
    if (tmp == s[a]) return 1;
    else return 0;
}

int main() {
    int n, i, j;
    char tmp[10000];
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s", &tmp);
        s[i] = string(tmp);
    }
    for (i = n - 1; i >= 1; i--) {
        for (j = i + 1; j <= n; j++) {
            if (check(i, j))
                if (dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        }
    }
    int ans = 0;
    for (i = 1; i <= n; i++)
        if (dp[i] > ans)
            ans = dp[i];
    printf("%d\n", ans + 1);
    return 0;
}

