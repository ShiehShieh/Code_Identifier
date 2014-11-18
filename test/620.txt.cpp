#include<iostream> 
using namespace std; 
class h 
{ 
public: 
int height,upper,lower; 
h() 
{ 
upper=lower=-1; 
} 
}; 
int main() 
{ 
int n,i,j; 
cin>>n; 
h *w=new h [n+1]; 
for(i=1;i<=n;i++) 
{ 
cin>>w[i].height;
if(i==1) 
w[i].lower=w[i].upper=1;
 
else 
{ 
for(j=1;j<i;j++) 
{ 
if(w[i].height==w[j].height) 

continue; 

else if(w[i].height>w[j].height) 
{ 
if(w[j].upper>=w[i].upper) 
w[i].upper=w[j].upper+1;
if(w[i].lower<w[i].upper) 
w[i].lower=w[i].upper;  
} 
else 
{ 
if(w[j].lower>=w[i].lower) 
w[i].lower=w[j].lower+1; 
} 
} 

} 

if(w[i].upper==-1) 
w[i].upper=1; 
} 
int max=0; 
for(i=1;i<=n;i++) 
{ 
if(max<w[i].upper) 
max=w[i].upper; 
if(max<w[i].lower) 
max=w[i].lower; 
} 
cout<<n-max;
return 0; 
} 
 
