#include <iostream>  
#include<string>
    

using namespace std;   
  
  
int main()         
{  
	const int a=8000,b=4000,c=2000,d=1000,e=850;
	int n,max=0,sum=0;
	char maxname[20];
    int maxscholarship;
	cin>>n;
	while (n--)
	{
		char name[20],x,y;
		int  score1,score2,thesis,scholarship=0; 
		
		cin>>name>>score1>>score2>>x>>y>>thesis;
		if (score1>80&&thesis!=0)
			scholarship+=a;
		if (score1>85&&score2>80)
			scholarship+=b;
		if (score1>90)
			scholarship+=c;
	    if (score1>85&&y=='Y')
			scholarship+=d;
		if(score2>80&&x=='Y')
			scholarship+=e;
		
		if (scholarship>max)
		{
			max=scholarship;
			strcpy(maxname,name);
			maxscholarship=scholarship;
		}
		sum+=scholarship;
	}
	cout<<maxname<<endl<<maxscholarship<<endl<<sum<<endl;




      
              
    return 0;         
}      
