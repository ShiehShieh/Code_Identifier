#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double a,b,o,p,a1,a2,r,tot;
int n;
double dis(double x1,double y1,double x2,double y2);
int main(){
    cin>>n>>r;
    cin>>o>>p;
    a1=o; a2=p;
    tot=3.1415926*2*r;
    for (int i=1;i<=n-1;i++){
        cin>>a>>b;
        tot=tot+dis(a,b,o,p);
        o=a; p=b;
        }
    tot=tot+dis(o,p,a1,a2);
    printf("%.2f",tot);
    return 0;
}

double dis(double x1,double y1,double x2,double y2){
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
       }

