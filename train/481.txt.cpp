#include<iostream>
using namespace std;
int v[510][510];
int dp[510][510];
bool used[510][510];
int search(int i, int j) {
    int max = 0;
    if (v[i][j] > v[i - 1][j]) {
        if (!used[i - 1][j]) max >?= search(i - 1, j);
        else max >?= dp[i - 1][j];
    }
    if (v[i][j] > v[i + 1][j]) {
        if (!used[i + 1][j]) max >?= search(i + 1, j);
        else max >?= dp[i + 1][j];
    }
    if (v[i][j] > v[i][j - 1]) {
        if (!used[i][j - 1]) max >?= search(i, j - 1);
        else max >?= dp[i][j - 1];
    }
    if (v[i][j] > v[i][j + 1]) {
        if (!used[i][j + 1]) max >?= search(i, j + 1);
        else max >?= dp[i][j + 1];
    }
    max++;
    dp[i][j] = max;
    used[i][j] = 1;
    return max;
}

int main() {
    int r, c, i, j, max, ans = 0;
    scanf("%d %d", &r, &c);
    memset(v,80,sizeof(v));
    for (i = 1; i <= r; i++)
        for (j = 1; j <= c; j++)
            scanf("%d", &v[i][j]);
    for (i = 1; i <= r; i++)
        for (j = 1; j <= c; j++) 
            ans >?= search(i, j);
    printf("%d\n", ans);
    return 0;
}
