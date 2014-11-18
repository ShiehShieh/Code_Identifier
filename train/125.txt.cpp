#include<iostream.h>
#include<time.h>
#include<string>
#include<math.h>
using namespace std;
const long bp=510509;
long ax,zax[4];
//SUF begin
typedef struct node
    {
    long p,n;         //p:prior n:next
    char t;           //type 1:&Ecirc;&yacute;×&Ouml; 2:&Ocirc;&Euml;&Euml;&atilde; 3:( 4:)
    char pri;//&Oacute;&Aring;&Iuml;&Egrave;&frac14;&para;
    char o;       //&Ocirc;&Euml;&Euml;&atilde;  
    int v;        //value
    };
node pi[1000];
long l=0;
void sufins(long b,long k)
    {
    long t=pi[k].p;
    pi[t].n=b;
    pi[b].p=t;
    pi[k].p=b;
    pi[b].n=k;    
    };
char pri(char o)//&Oacute;&Aring;&Iuml;&Egrave;&frac14;&para; 
    {
    switch(o)
      {
      case('+'):
        {
        return 1;
        break;};
      case('-'):
        {
        return 1;
        break;};
      case('*'):
        {
        return 2;
        break;};
      case('^'):
        {
        return 3;
        break;};
      };
    return 0;
    };
/*void debug1()
    {
    for(long i=pi[0].n;i!=0;i=pi[i].n)
        cout<<"!"<<(int)pi[i].t<<pi[i].v;
    cout<<endl;
    };*/
void suffix()
    {
    bool flag;
    long i,p=0;
    long st[1000],stl=0;
    pi[0].p=pi[0].n=pi[0].t=0;
    st[stl]=0;
    for(i=1;i<=l;i++)
        switch(pi[i].t)
          {
          case 1:
            {
            sufins(i,p);
            break;};
          case 2:
            {
            flag=true;
            while(p!=st[stl])
                if(pi[p].pri<pi[i].pri)
                    {
                    sufins(i,p);
                    p=pi[p].p;
                    flag=false;
                    break;
                    }
                  else
                    p=pi[p].n;
            if(flag)
                {
                sufins(i,p);
                p=pi[p].p;
                };
            break;};
          case 3:
            {
            stl++;
            st[stl]=p;
            break;};
          case 4:
            {
            p=st[stl];
            stl--;
            break;};  
          };
    };
long long calcu()
    {
    long ctl=-1,j;
    long long ct[1000],tt;
    for(long i=pi[0].n;i!=0;i=pi[i].n)
        switch(pi[i].t)
          {
          case(1):
            {
            ctl++;
            ct[ctl]=pi[i].v;//cout<<"PUSH"<<pi[i].v<<endl;
            break;};
          case(2):
            {
            ctl--;//cout<<"PUSH"<<pi[i].o<<endl;
            switch(pi[i].o)
              {
              case('+'):
                {
                ct[ctl]+=ct[ctl+1];
                break;};
              case('-'):
                {
                ct[ctl]-=ct[ctl+1];
                break;};
              case('*'):
                {
                ct[ctl]*=ct[ctl+1];
                break;};
              case('^'):
                {
                tt=ct[ctl];
                for(j=1;j<ct[ctl+1];j++)
                   ct[ctl]=(ct[ctl]*tt)%bp;
                break;};
              case('a'):
                {
                ctl+=2;
                ct[ctl]=ax;
                break;};      
              };
            ct[ctl]%=bp;
            break;};
          };
    if(ct[0]<0)
        ct[0]+=bp;
    return ct[0];
    };
//SUF end
void z(string s,long long *re)
    {
    long i,p=0,t,le;
    le=s.length();
    l=0;
    while(p<le)
        {
        while((p<le)&&(s[p]==' '))
            p++;
        if(p>=le)
            break;
        t=p;
        while((s[p]<='9')&&(s[p]>='0')&&(p<le))
            p++;//cout<<"p"<<p<<" t"<<t<<endl;
        if(t==p)
            {
            switch(s[t])
              {
              case('a'):
                {
                l++;
                p++;
                pi[l].t=2;
                pi[l].pri=4;
                pi[l].o=s[t];
                break;};
              case('('):
                {
                l++;
                p++;
                pi[l].t=3;
                break;};
              case(')'):
                {
                l++;
                p++;
                pi[l].t=4;
                break;};
              default:
                {
                l++;
                p++;
                pi[l].o=s[t];
                pi[l].t=2;
                pi[l].pri=pri(s[t]);
                };
              };
            }
          else
            {
            l++;
            pi[l].t=1;
            pi[l].pri=4;
            pi[l].v=atol((s.substr(t,p-t)).c_str());//cout<<l<<"::"<<pi[l].v<<endl;
            };
        };
    suffix();
    for(i=0;i<4;i++)
        {
        ax=zax[i];
        re[i]=calcu();
        //cout<<"RE:"<<i<<"="<<"("<<ax<<")"<<re[i]<<endl;
        };
    };
int main()
    {
    long i,j,n,rig;
    long long ra[4],an[4];
    srand(((unsigned)time(NULL)));
    string litt,a,b[26];
    getline(cin,a);
    cin>>n;
    getline(cin,litt);
    for(i=0;i<n;i++)
        getline(cin,b[i]);
    for(i=0;i<4;i++)
        zax[i]=rand()%6+5;
    z(a,ra);
    for(i=0;i<n;i++)
        {
        z(b[i],an);
        rig=0;
        for(j=0;j<4;j++)
           if(ra[j]==an[j])
               rig++;
        if(rig>=3)
            cout<<(char)(i+'A');
        };
    cout<<endl;
    return 0;
    };
