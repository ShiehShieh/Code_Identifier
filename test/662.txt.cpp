#include <stdio.h>

#define MAXN 20

int main()
{
    long bi, bj, ci, cj, i, j, m[MAXN][MAXN] = { 0 }, f[MAXN][MAXN] = { 0 };

    scanf("%d %d %d %d", &bi, &bj, &ci, &cj);

    m[ci][cj] = 1;
    m[ci + 2][cj - 1] = 1;
    m[ci + 2][cj + 1] = 1;
    m[ci + 1][cj - 2] = 1;
    m[ci + 1][cj + 2] = 1;
    m[ci - 1][cj - 2] = 1;
    m[ci - 1][cj + 2] = 1;
    m[ci - 2][cj - 1] = 1;
    m[ci - 2][cj + 1] = 1;

    f[0][0] = 1;
for (i = 1; i <= bi; ++i)
        if (0 == m[i][0])
            f[i][0] = f[i - 1][0];
for (j = 1; j <= bj; ++j)
        if (0 == m[0][j])
            f[0][j] = f[0][j - 1];
    for (i = 1; i <= bi; ++i)
    {
        for (j = 1; j <= bj; ++j)
        {
            if (m[i][j])
                continue;
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    printf("%ld\n", f[bi][bj]);
    return 0;
}
