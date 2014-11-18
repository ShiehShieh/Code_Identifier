#include<iostream>
#include<cmath>
using namespace std;
int main()
{ 
    int a,b,c,d;
    double temp; 
    cin>>a>>b>>c>>d;
    temp=sqrt(2*sqrt(b*d)+b+d+(a-c)*(a-c));
    printf("%0.3f",temp);
        
    
}

