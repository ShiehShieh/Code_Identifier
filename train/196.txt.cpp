#include <stdio.h>

#define MAXN 21

int map[MAXN][MAXN], f[2 * MAXN - 1][MAXN][MAXN][MAXN] = { 0 }, way[8][3] =
 {{0, 0, 0}, {-1, 0, 0}, {0, -1, 0}, {-1, -1, 0}, {0, 0, -1}, {-1, 0, -1},
  {0, -1, -1}, {-1, -1, -1}};

int main()
{
    int n, i, j, k, p, i1, i2, i3, j1, j2, j3;

    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            scanf("%d", &map[i][j]);
    }

    for (k = 1; k <= 2 * n - 1; ++k)
    {
        for (i1 = 1; i1 <= n; ++i1)
        {
            for (i2 = 1; i2 <= n; ++i2)
            {
                for (i3 = 1; i3 <= n; ++i3)
                {
                    j1 = k + 1 - i1;
                    j2 = k + 1 - i2;
                    j3 = k + 1 - i3;

                    if (j1 < 1 || j2 < 1 || j3 < 1)
                        continue;

                    for (p = 0, i = 0; i < 8; ++i)
                    {
                        j = f[k - 1][i1 + way[i][0]][i2 + way[i][1]][i3 + way[i][2]];
                        if (p < j)
                            p = j;
                    }

                    if ((i1 == i2 && j1 == j2) && (i2 == i3 && j2 == j3))
                        f[k][i1][i2][i3] = p + map[i1][j1];
                    else if ((i1 == i2 && j1 == j2) || (i2 == i3 && j2 == j3))
                        f[k][i1][i2][i3] = p + map[i1][j1] + map[i3][j3];
                    else if ((i1 == i3 && j1 == j3) || (i2 == i3 && j2 == j3))
                        f[k][i1][i2][i3] = p + map[i1][j1] + map[i2][j2];
                    else
                        f[k][i1][i2][i3] = p + map[i1][j1] + map[i2][j2] + map[i3][j3];
                }
            }
        }
    }

    printf("%d\n", f[k - 1][n][n][n]);

    return 0;
}
