#include<iostream>
using namespace std;
char a[1002][1002];
int dp[1002][1002], n;

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

void sol(int t) {
    int i, j;
    for (j = 1; j <= t; j++) {
        for (i = j + 1; i <= t; i++)
            if (dp[t][i] > dp[t][i - 1] + a[t][i]) dp[t][i] = dp[t][i - 1] + a[t][i];
        if (dp[t][1] > dp[t][t] + a[t][1]) dp[t][1] = dp[t][t] + a[t][1];
        for (i = 2; i <= j; i++)
            if (dp[t][i] > dp[t][i - 1] + a[t][i]) dp[t][i] = dp[t][i - 1] + a[t][i];
        for (i = j - 1; i >= 1; i--)
            if (dp[t][i] > dp[t][i + 1] + a[t][i]) dp[t][i] = dp[t][i + 1] + a[t][i];
        if (dp[t][t] > dp[t][1] + a[t][t]) dp[t][t] = dp[t][1] + a[t][t];
        for (i = t - 1; i >= j; i--)
            if (dp[t][i] > dp[t][i + 1] + a[t][i]) dp[t][i] = dp[t][i + 1] + a[t][i];
    }
}

int main() {
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
    memset(dp, 80, sizeof (dp));
    dp[n][1] = a[n][1];
    for (i = n; i >= 2; i--) {
        sol(i);
        for (j = 1; j <= i - 1; j++)
            dp[i - 1][j] = min(dp[i][j], dp[i][j + 1]) + a[i - 1][j];
        if (dp[i - 1][1] > dp[i][i] + a[i - 1][1]) dp[i - 1][1] = dp[i][i] + a[i - 1][1];
        if (dp[i - 1][i - 1] > dp[i][1] + a[i - 1][i - 1]) dp[i - 1][i - 1] = dp[i][1] + a[i - 1][i - 1];
    }
    printf("%d\n", dp[1][1]);
    return 0;
}
