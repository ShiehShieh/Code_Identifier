#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    int c;
    int n[18];
    int stick;
    int test;
    int count;
    int ten;
    int one;
    
    n[0]=6;
    n[1]=2;
    n[2]=5;
    n[3]=5;
    n[4]=4;
    n[5]=5;
    n[6]=6;
    n[7]=3;
    n[8]=7;
    n[9]=6;
    count=0;
    
    
    cin>>stick;
    cin.ignore();
    
    for (a=0;a<=999;a++) {
        for (b=0;b<=999;b++) {
            c=a+b;
            test=0;
            
            if (a>99) { 
                     test=test+n[a/100]+n[(a-a/100*100)/10]+n[a%10];  
                } 
                else if (a>9) {
                       test=test+n[a/10]+n[a%10];
                }
                else {
                     test=test+n[a];
                }
            
            if (b>99) { 
                     test=test+n[b/100]+n[(b-b/100*100)/10]+n[b%10];  
                } 
                else if (b>9) {
                       test=test+n[b/10]+n[b%10];
                }
                else {
                     test=test+n[b];
                }
            
            if (c>99) { 
                     test=test+n[c/100]+n[(c-c/100*100)/10]+n[c%10];  
                } 
                else if (c>9) {
                       test=test+n[c/10]+n[c%10];
                }
                else {
                     test=test+n[c];
                }
                
            test=test+4;
            if (test==stick) {
                             count=count+1;
            }
        }
    }
    cout<<count<<"\n";
    cin.get();
}

