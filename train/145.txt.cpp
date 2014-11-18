#include <cstdlib>
#include <iostream>

using namespace std;


struct Student
    {
           char name[20];
           int cj1;
           int cj2;
           char gb;
           char west;
           int lw;
           int jxj;
   }stud[100];
   
   


int main()
{  int n,i;
   cin>>n;
    for(i=0;i<n;i++) stud[i].jxj=0;

    for(i=0;i<n;i++)
       {cin>>stud[i].name;
       cin>>stud[i].cj1;
       cin>>stud[i].cj2;
       cin>>stud[i].gb;
       cin>>stud[i].west;
       cin>>stud[i].lw;
       
   }
   
   for(i=0;i<n;i++)
       { if(stud[i].cj1>80&&stud[i].lw>0) stud[i].jxj+=8000;
     
         if(stud[i].cj1>85&&stud[i].cj2>80) stud[i].jxj+=4000;
       
          if(stud[i].cj1>90) stud[i].jxj+=2000;
        
          if(stud[i].cj1>85&&stud[i].west=='Y') stud[i].jxj+=1000;
     
          if(stud[i].cj2>80&&stud[i].gb=='Y') stud[i].jxj+=850;}
   int x=0,y=0;
   double zhongjxj=0;
   for(i=0;i<n;i++)
        {
        if(stud[i].jxj>x) {x=stud[i].jxj;y=i;}
        zhongjxj+=stud[i].jxj;
                   }
cout<<stud[y].name<<endl;
cout<<x<<endl;
cout<<zhongjxj;
    
    
    return 0;
}

