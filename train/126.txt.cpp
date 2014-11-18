#include <stdio.h>
int main()
{   int n,i,j,m=0,goon=1;
    __int64 l=1,ans=0;
    scanf("%d",&n);
    for(i=0;goon;++i)
       {if(i==0)l=1;
        else    l*=2;
        if (l>10000)
            l %= 10000;
        for (j = 0; j < i + 1; ++j)
        {
            ans += l;
            if (ans > 10000)
                ans %= 10000;
            ++m;
            if (m==n)
               {goon=0;
                break;
            }
        }
    }
    printf("%ld\n", ans);
    return 0;
}
