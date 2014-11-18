#include <stdio.h>

#define MAXN 1501

#define MAXINT 2000000000

typedef struct

{

        int v, num;

        int child[MAXN];

}node;

node a[MAXN];

int f[MAXN][4];

int min2(int x, int y)

{

        return x<y?x:y;

}

int min3(int x, int y, int z)

{

        return min2(x, min2(y, z));

}

void dp(int i)

{

        int j, k,a2;

        if (a[i].num == 0)

        {

               f[i][1] = a[i].v;

               f[i][2] = a[i].v;

               return;

        }

        f[i][2] = a[i].v;

        for (j = 1; j <= a[i].num; j++)

        {

               dp(a[i].child[j]);

               f[i][2] += min3(f[a[i].child[j]][1], f[a[i].child[j]][2], f[a[i].child[j]][3]);

               f[i][3] += f[a[i].child[j]][1];

        }

        f[i][1] = MAXINT;

        for (j = 1; j <= a[i].num; j++)

        {

               a2 = f[a[i].child[j]][2];

               for (k = 1; k <= a[i].num; k++)

               {

                      if (j != k)

                      {

                             if (a[a[i].child[k]].num != 0)

                                    a2 += min2(f[a[i].child[k]][2], f[a[i].child[k]][1]);

                             else

                                    a2 += f[a[i].child[k]][2];

                      }

               }

               if (a2 < f[i][1])

                      f[i][1] = a2;

        }

}

int main()

{

        int i, j, m, n, p,   r, root;

        m = MAXINT;

        r = 0;

        root = 0;

        scanf("%d", &n);

        for (i = 1; i <= n; i++)

        {

               scanf("%d", &p);

               scanf("%d%d", &a[p].v, &a[p].num);

               r += p;

               for (j = 1; j <= a[p].num; j++)

               {

                      scanf("%d", &a[p].child[j]);

                      root += a[p].child[j];

               }

        }

        root = r - root;

//      printf("root=%d\n", root);

        dp(root);

        if (a[root].num != 0)

               printf("%d\n", min2(f[root][1], f[root][2]));

        else

               printf("%d\n", f[root][2]);

        return 0;

}
