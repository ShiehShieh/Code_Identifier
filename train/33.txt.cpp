/*NOIP2007 &Igrave;á&cedil;&szlig;×é &frac34;&Oslash;&Otilde;ó&Egrave;&iexcl;&Ecirc;&yacute;&Oacute;&Icirc;&Iuml;·*/
#include<iostream.h>
using namespace std;
typedef /*unsigned*/ long word;
typedef /*unsigned*/ long dword;
typedef struct hn
    {
    dword l;
    word *d;
    };
dword max(dword a,dword b)
    {
    if(a<b)
        return b;
      else
        return a;
    };
void free(hn *s)
    {
    delete [] s->d;
    };
void mov(hn *s,hn *a)
    {
    long i;
    delete [] s->d;
    s->l=a->l;
    s->d=new word[s->l];
    for(i=0;i<s->l;i++)
        s->d[i]=a->d[i];
    };
void carr(hn *s)
    {
    dword l;
    long i;
    hn t;
    l=s->l;
    t.d=new word[s->l+4];
    for(i=0;i<l;i++)
        t.d[i]=s->d[i];
    for(i=l;i<l+4;i++)
        t.d[i]=0;
    i=0;
    while(i<l+1)
        {
        if(t.d[i]>=10000)
            {
            t.d[i+1]+=t.d[i]/10000;
            t.d[i]%=10000;
            };
        i++;
        };
    i--;
    while((t.d[i]==0)&&(i>0))
        i--;
    t.l=i+1;
    mov(s,&t);
    free(&t);
    };
void inva(hn *s,word p)
    {
    delete [] s->d;
    s->l=1;
    s->d=new word[1];
    s->d[0]=p;
    carr(s);
    };
void point(hn *s)
    {
    long i;
    cout<<s->d[s->l-1];
    for(i=s->l-2;i>=0;i--)
        cout<<(s->d[i])/1000<<(s->d[i])/100%10<<(s->d[i])/10%10<<(s->d[i])%10;
    };
bool big(hn *a,hn *b)
    {
    if(a->l<b->l)
        return false;
      else
        if(a->l>b->l)
            return true;
          else
            {
            long i;
            for(i=a->l-1;i>=0;i--)
                {
                if(a->d[i]==b->d[i])
                    continue;
                if(a->d[i]<b->d[i])
                    return false;
                  else
                    return true;
                };
            return false;
            };
    };
void add(hn *s,hn *a)
    {
    long i;
    if(s->l>=a->l)
        {
        for(i=0;i<a->l;i++)
            s->d[i]+=a->d[i];
        }
      else
        {
        hn t;
        mov(&t,s);
        free(s);
        mov(s,a);
        for(i=0;i<t.l;i++)
            s->d[i]+=t.d[i];        
        free(&t);
        };
    carr(s);
    };
void multp(hn *s,hn *a,word p)
    {
    long i;
    free(s);
    s->d=new word[a->l];
    s->l=a->l;
    for(i=0;i<a->l;i++)
        s->d[i]=a->d[i]*p;
    carr(s);
    };
int main()
    {
    long n,m,i,j,k,a[80][80];
    hn max,all,pow2[81],f[81][81],t1,t2;
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    inva(&pow2[0],1);
    for(i=1;i<=m;i++)
        {
        mov(&pow2[i],&pow2[i-1]);
        add(&pow2[i],&pow2[i-1]);
        };
    inva(&all,0);
    for(i=0;i<n;i++)
        {
        inva(&max,0);
        inva(&f[0][0],0);
        for(j=1;j<=m;j++)
            {
            multp(&f[j][0],&pow2[j],a[i][j-1]);
            add(&f[j][0],&f[j-1][0]);
            multp(&f[0][j],&pow2[j],a[i][m-j]);
            add(&f[0][j],&f[0][j-1]);            
            };
        for(j=1;j<=m;j++)
            for(k=1;k<=m-j;k++)
                {
                multp(&t1,&pow2[j+k],a[i][j-1]);
                add(&t1,&f[j-1][k]);
                multp(&t2,&pow2[j+k],a[i][m-k]);
                add(&t2,&f[j][k-1]);
                if(big(&t1,&t2))
                    mov(&f[j][k],&t1);
                  else
                    mov(&f[j][k],&t2);
                };
        for(j=0;j<=m;j++)
            if(big(&f[j][m-j],&max))
                mov(&max,&f[j][m-j]);
        add(&all,&max);
        };
    point(&all);
    cout<<endl;
    free(&t1);
    free(&t2);
    free(&max);
    free(&all);
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            free(&f[i][j]);
    for(i=0;i<=m;i++)
        free(&pow2[i]);
    return 0;
    };
