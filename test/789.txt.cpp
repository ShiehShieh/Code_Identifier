#include <stdio.h>

#include <string.h>

#define MAXN 200

int main()

{

       int n, a[MAXN], b[MAXN], c[MAXN], i, j, max;

       scanf("%d", &n);

       for (i = 1; i <= n; i++)

              scanf("%d", &a[i]);

       memset(b, 0, sizeof(a));

       memset(c, 0, sizeof(c));

       b[1] = 1;

       for (i = 2; i <= n; i++)

       {

              max = 0;

              for (j = i - 1; j >= 1; j--)

              {

                     if (a[j] < a[i] && b[j] + 1 > max)

                            max = b[j];

              }

              b[i] = max + 1;

       }

       c[n] = 1;

       for (i = n - 1; i > 0; i--)

       {

              max = 0;

              for (j = i + 1; j <= n; j++)

              {

                     if (a[j] < a[i] && c[j] + 1 > max)

                            max = c[j];

              }

              c[i] = max + 1;

       }

       max = b[1] + c[1];

       for (i = 2; i <= n; i++)

       {

              if (b[i] + c[i] > max)

                     max = b[i] + c[i];

       }

       printf("%d\n", n - max + 1);

       return 0;

}

