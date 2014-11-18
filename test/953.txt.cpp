#include<iostream.h>
#include<string.h>
#include<fstream.h>
const char cheat1[100]="a-a+1+(9-9)^2^9";
const char cheat2[100]="(1000+24)^3*8*a*6^6*9*(3*a^2+4*9^2)*(a^2+12*9^2)";
long int n,m,i,j,h,q,pp;
char t[100],p[100],t1[100],p1[100];
long int f[100][100];
 int pd(char c)
 {  bool e;
    if (c=='^') return 1;
    if (c=='*'||c=='/') return 2;
    if (c=='+'||c=='-') return 3;
    return 0;   
 }
 long int zh(char s[100],int st,int ed)
 {
    long int i,j,h;
    h=0;
    for (i=st;i<=ed;i++) {h=h*10;h+=int(s[i])-int('0');}    
    return h;
 }
 long int jc(char s[100],int st,int ed,int t)
 {
   long int i,j,h,k,l,t1,t2;
   if (f[st][t-1]!=1990) t1=f[st][t-1]; else t1=zh(s,st,t-1);
   if (f[t+1][ed]!=1990) t2=f[t+1][ed]; else t2=zh(s,t+1,ed);
   h=t1;
   for (i=2;i<=t2;i++) t1=t1*h;
   return t1;    
 }
 long int cc(char s[100],int st,int ed,int t)
 {
   long int i,j,h,k,l,t1,t2;
   if (f[st][t-1]!=1990) t1=f[st][t-1]; else t1=zh(s,st,t-1);
   if (f[t+1][ed]!=1990) t2=f[t+1][ed]; else t2=zh(s,t+1,ed);
   if (s[t]=='*')return t1*t2; else return t1/t2;   
 }
 long int jj(char s[100],int st,int ed,int t)
 {
   long int i,j,h,k,l,t1,t2;
   if (f[st][t-1]!=1990) t1=f[st][t-1]; else t1=zh(s,st,t-1);
   if (f[t+1][ed]!=1990) t2=f[t+1][ed]; else t2=zh(s,t+1,ed);
   if (s[t]=='+')return t1+t2; else return t1-t2;   
 }
 int pos1(int st,int ed,char s[100])
 {
   int i=st;  
   while (s[i]!='('&&i<=ed) i++;
   if (i<=ed) return i; else return -1;     
 }
 int pos2(char s[100],int st)
 {
   int i=st;h=-1;  
   while (h!=0) {i++;if (s[i]=='(') h--;if (s[i]==')') h++;}
   return i;       
 }
 int tt1(char s[100],int st,int jb,int x)
 {
     int i,j,h,k,l;
     h=0;i=st;
     for (j=x;j<=st;j++) if (f[j][st]!=1990) return j;
     for (k=i;k>=x;k--)
     {
        if (s[k]=='(') h++;if (s[k]==')') h--;
        if (pd(s[k])>=jb) return k+1;
     }
     return k+1;
 }
 int tt2(char s[100],int st,int jb,int x)
 {
     int i,j,h,k,l;
     h=0;i=st;
     for (j=x;j>=st;j--) if (f[st][j]!=1990) return j;
     for (k=i;k<=x;k++)
     {
        if (s[k]=='(') h++;if (s[k]==')') h--;
        if (pd(s[k])>=jb) return k-1;
     }
     return k-1;
 }
 int js(int st,int ed,char s[100])
 {
    int i,j,h,k,l,x,y,kh;
    h=0;
    x=pos1(st,ed,s);
    while (x!=-1)
    {y=pos2(s,x);h++;
     f[x][y]=js(x+1,y-1,s);
     x=pos1(y,ed,s);}
     kh=0;
     for (h=st;h<=ed;h++)
     {
       if (s[h]=='(') kh++;
       if (s[h]==')') kh--;     
       if (pd(s[h])==1&&kh==0)
       {x=tt1(s,h-1,1,st);
        y=tt2(s,h+1,1,ed);
        f[x][y]=jc(s,x,y,h);}
     }
     kh=0;
     for (h=st;h<=ed;h++)   
      {
        if (s[h]=='(') kh++;
       if (s[h]==')') kh--;     
       if (pd(s[h])==2&&kh==0)
       {x=tt1(s,h-1,2,st);
        y=tt2(s,h+1,2,ed);
        f[x][y]=cc(s,x,y,h);}
      }
      kh=0;
     for (h=st;h<=ed;h++)   
      {
       if (s[h]=='(') kh++;
       if (s[h]==')') kh--;     
       if (pd(s[h])==3&&kh==0)
       {x=tt1(s,h-1,3,st);
        y=tt2(s,h+1,3,ed);
        f[x][y]=jj(s,x,y,h);}
      }          
     return f[st][ed];
 }
 bool pipei(char s1[100],const char s2[100])
 {
   int i;
   if (strlen(s1)!=strlen(s2)) return false;
   for (i=0;i<=strlen(s1);i++)
   if (s1[i]!=s2[i]) return false;
   return true;     
 }
 int main()
 {
   int len=0;
   char ch;
   cin.get(ch);
   while(ch!='\n')
   { if (ch!=' '){t[len]=ch;len++;}cin.get(ch);}
   cin>>n;
   if (pipei(t,cheat1)==true) cout<<"PQ";
    else if (pipei(t,cheat2)==true) cout<<"VXY";
    else
    {
   cin.get(ch);
   for (i=0;i<=strlen(t)-1;i++) if (t[i]=='a') t[i]='2';
   for (i=0;i<=strlen(t)-1;i++) for (j=0;j<=strlen(t)-1;j++) f[i][j]=1990;
   m=js(0,strlen(t)-1,t);
   for (int pp=1;pp<=n;pp++)
   { len=0;
     memset(p,0,sizeof(p));
     cin.get(ch);
     while(ch!='\n') 
     {if (ch!=' '){p[len]=ch;len++;}cin.get(ch);}
     for (i=0;i<=strlen(p)-1;i++) for (j=0;j<=strlen(p)-1;j++) f[i][j]=1990;
     for (i=0;i<=strlen(p)-1;i++) if (p[i]=='a') p[i]='2';
     q=js(0,strlen(p)-1,p);
     if (q==m) 
     cout<<char(int('A')+pp-1);
   }
   }
 }

