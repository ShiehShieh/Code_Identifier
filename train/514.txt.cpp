#include<iostream>
using namespace std;
int w[22][22][22];

int solve(int a, int b, int c) {
    if (w[a][b][c] != 0) return w[a][b][c];
    int i, j, k;
    if (a <= 0 || b <= 0 || c <= 0) {
        w[a][b][c] = 1;
        return 1;
    }
    if (a < b && b < c) {
        w[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
        return w[a][b][c];
    } else {
        w[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
        return w[a][b][c];
    }
}

int main() {
    int a, b, c, i, j, k, ta, tb, tc;
    while (1) {
        scanf("%d %d %d", &ta, &tb, &tc);
        if (ta == -1 && tb == -1 && tc == -1) return 0;
        if (ta > 20) a = 20;
        else a = ta;
        if (tb > 20) b = 20;
        else b = tb;
        if (tc > 20) c = 20;
        else c = tc;
        if (a <= 0 || b <= 0 || c <= 0) {
            printf("w(%d,%d,%d) = 1\n", ta, tb, tc);
            continue;
        }
        for (i = 1; i <= a; i++)
            for (j = 1; j <= b; j++)
                for (k = 1; k <= c; k++)
                    w[i][j][k] = solve(i, j, k);
        printf("w(%d,%d,%d) = %d\n", ta, tb, tc, w[a][b][c]);
    }
    return 0;
}
