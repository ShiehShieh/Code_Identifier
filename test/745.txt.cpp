#include<iostream>
using namespace std;
long n,m,i,j;
bool a[2000][2000];
long max(int a,int b)
    {
    if(a>b)
        return a;
      else
        return b;
    }
void giv(int &a,int &b)
    {
    if(a>b)
        a=b;
    }
long f1()
    {
    int f[4000];
    long max=1;
    for(i=0;i<m+n-1;i++)
        f[i]=1;
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
            if((a[i][j]==a[i][j-1])&&(a[i][j]==a[i-1][j])&&(a[i][j]==a[i-1][j-1]))
                {
                giv(f[n-i+j-1],f[n-i+j-2]);
                giv(f[n-i+j-1],f[n-i+j]);
                f[n-i+j-1]++;
                if(max<f[n-i+j-1])
                    max=f[n-i+j-1];
                }
              else
                f[n-1-i+j]=1;
    return max*max;
    }
bool sm[2000];
int l1[2000],l2[2000],h1,h2;
long f(int l,int t,int r,int b)
    {
    if((l==r)&&(t==b))
        return 1;
    long ans,q;
    if((r-l)<(b-t))
        {//&ordm;á&Ccedil;&ETH; 
        q=t+b>>1;
        ans=max(f(l,t,r,q),f(l,q+1,r,b));
        for(i=l;i<=r;i++)
            sm[i]=!(a[q][i]^a[q+1][i]);
        for(i=l;i<=r;i++)
            if(sm[i])
                {
                for(j=q;j>=t;j--)
                    if(a[j][i]!=a[q][i])
                        break;
                l1[i]=q-j;
                for(j=q+1;j<=b;j++)
                    if(a[j][i]!=a[q+1][i])
                        break;
                l2[i]=j-q-1;
                }
        for(i=l;i<=r;i++)
            {
            if(!sm[i])
                continue;
            h1=h2=10000;
            for(j=i;j<=r;j++)
                {
                if((!sm[j])||(a[q][j]!=a[q][i]))
                    break;
                if(h1>l1[j])
                    h1=l1[j];
                if(h2>l2[j])
                    h2=l2[j];
                if(ans<(h1+h2)*(j+1-i))
                    ans=(h1+h2)*(j+1-i);
                //cout<<">>> "<<l<<" "<<t<<" "<<r<<" "<<b<<" = "<<(h1+h2)*(j+1-i)<<endl;
                }
            }
        }
      else
        {//&Ouml;±&Ccedil;&ETH; 
        q=l+r>>1;
        ans=max(f(l,t,q,b),f(q+1,t,r,b));
        for(i=t;i<=b;i++)
            sm[i]=!(a[i][q]^a[i][q+1]);
        for(i=t;i<=b;i++)
            if(sm[i])
                {
                for(j=q;j>=l;j--)
                    if(a[i][j]!=a[i][q])
                        break;
                l1[i]=q-j;
                for(j=q+1;j<=r;j++)
                    if(a[i][j]!=a[i][q+1])
                        break;
                l2[i]=j-q-1;
                }
        for(i=t;i<=b;i++)
            {
            if(!sm[i])
                continue; //&sup2;&raquo;&Ecirc;&Ccedil;break; 
            h1=h2=10000;
            for(j=i;j<=b;j++)
                {
                if((!sm[j])||(a[j][q]!=a[i][q]))
                    break;
                if(h1>l1[j])
                    h1=l1[j];
                if(h2>l2[j])
                    h2=l2[j];
                if(ans<(h1+h2)*(j+1-i))
                    ans=(h1+h2)*(j+1-i);
                //cout<<">>> "<<l<<" "<<t<<" "<<r<<" "<<b<<" = "<<(h1+h2)*(j+1-i)<<endl;
                }
            }
        }
    return ans;
    }
long f2()
    {
    return f(0,0,m-1,n-1);//×&cent;&Ograve;&acirc;&Otilde;&acirc;&Igrave;&acirc;&sup2;&raquo;&Ecirc;&Ccedil;&Otilde;&yacute;·&frac12;&ETH;&Icirc; &para;&oslash;&Ecirc;&Ccedil;&frac34;&Oslash;&ETH;&Icirc;!!! 
    }
int main()
    {
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            {
            scanf("%d",&a[i][j]);
            a[i][j]^=(i+j)&1;//&Ntilde;§pascal&Ecirc;±&frac12;&acirc;&frac34;&ouml;&micro;&Auml;·&frac12;·¨&pound;&not;&Otilde;&acirc;&Ntilde;ù&frac14;&acute;×&ordf;&Icirc;&Ecirc;&Igrave;&acirc;&Icirc;&ordf;&Egrave;&iexcl;&Iacute;&not;&Eacute;&laquo;·&frac12;&cedil;&ntilde;; &Icirc;&raquo;&Ocirc;&Euml;&Euml;&atilde;·&ucirc;&ordm;&Aring;&sup2;&raquo;&Ograve;&ordf;&cedil;ú&Acirc;&szlig;&frac14;&shy;&Ocirc;&Euml;&Euml;&atilde;·&ucirc;&ordm;&Aring;&cedil;&atilde;&acute;í  
            }
    cout<<f1()<<endl<<f2()<<endl;
    return 0;
    }
