//&Atilde;&para;&frac34;&Ugrave; 
#include<iostream.h>
using namespace std;
int main()
    {
    long k,v1,v2,v3,v4;
    double time,min=2048,x1,x2,x3,x4;
    cin>>k>>x1>>x2>>x3>>x4;
    for(v1=0;v1<=10;v1++)
        for(v2=0;v2<=10;v2++)
            for(v3=0;v3<=10;v3++)
                if(v1+v2+v3<=k)
                    {
                    v4=k-v1-v2-v3;
                    time=(((100-v2*7)*x2)*2+((100-v3*9)*x3))/((10+v4)*x4)+((20-v1*2)*x1);
                    if(time<min) 
                        min=time;
                    };
    cout.setf(ios::fixed); 
    cout.setf(ios::showpoint); 
    cout.precision(3); 
    cout<<min<<endl;
    return 0;
    };
