//ISBN号码。2008普及组第一题 
#include<iostream>
using namespace std;
int main()
{
    int a[2],b[4],c[6],d,e;
    char x[12];
    cin>>x;
    a[1]=(int)x[0]-48;
    b[1]=(int)x[2]-48;
    b[2]=(int)x[3]-48;
    b[3]=(int)x[4]-48;
    c[1]=(int)x[6]-48;
    c[2]=(int)x[7]-48;
    c[3]=(int)x[8]-48;
    c[4]=(int)x[9]-48;
    c[5]=(int)x[10]-48;
    if(x[12]=='X') d=10;
    if(x[12]!='X')d=(int)x[12]-48;
    e=(a[1]+b[1]*2+b[2]*3+b[3]*4+c[1]*5+c[2]*6+c[3]*7+c[4]*8+c[5]*9)%11;
    if(d==e)
    {
            cout<<"Right";
            return(0);
            }
            if(d!=e&&e!=10)
            {
                           for(int i=0;i<12;i++)
                           cout<<x[i];
                           cout<<e;
                           return(0);
                           }
                           if(d!=e&&e==10)
                           {
                                          for(int i=0;i<12;i++)
                                          cout<<x[i]; 
                                          cout<<"X";
                                          return(0);
                                          }
                                          }

