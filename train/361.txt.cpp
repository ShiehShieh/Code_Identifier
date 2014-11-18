#include<iostream>
using namespace std;
int bf[100000][2];
int bf2[100000][2];
main(){
       char a;
       int t1=0,t2=0;
       int f1=0,f2=0;
       int f12=0,f11=0;
       a='a';
       while(a!='e')
       {
       a=getchar();
                   if (a=='W') {
                               f11++;
                               f1++;
                               }
                   if (a=='L'){
                               f12++;
                               f2++;
                               }
                   if ((f1>=11||f2>=11)&&((f1-f2)>=2||(f2-f1)>=2)){
                                                                   bf[t1][0]=f1;
                                                                   bf[t1][1]=f2;
                                                                   t1++;
                                                                   //cout<<f1<<':'<<f2<<'\n';
                                                                   f1=0;
                                                                   f2=0;
                                                                   }
                   if ((f11>=21||f12>=21)&&((f11-f12)>=2||(f12-f11)>=2)){
                                                                   bf2[t2][0]=f11;
                                                                   bf2[t2][1]=f12;
                                                                   t2++;
                                                                   //cout<<f1<<':'<<f2<<'\n';
                                                                   f11=0;
                                                                   f12=0;
                                                                   }
                   if (a=='E'){
                               bf[t1][0]=f1;
                               bf[t1][1]=f2;
                               bf2[t2][0]=f11;
                               bf2[t2][1]=f12;
                               break;
                               //cout<<f1<<':'<<f2<<'\n';
                               }
                    }
                    int i;
       for (i=0;i<=t1;i++)
       {
           cout<<bf[i][0]<<':'<<bf[i][1]<<'\n';
       }
       cout<<'\n';
       for (i=0;i<=t2;i++)
       {
           
           cout<<bf2[i][0]<<':'<<bf2[i][1]<<'\n';
       }
       }

