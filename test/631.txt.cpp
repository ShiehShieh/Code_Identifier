#include<iostream.h>
int n,max,t,total;
char name[150][50];
int jiang[150],c1[150],c2[150],lun[150];
bool gb[150],xb[150];  
  void init()
  {
     char x;  
     cin>>n;
     for (int i=1;i<=n;i++)
     {
        cin>>name[i];
        cin>>c1[i]>>c2[i];
        cin>>x;
        if (x=='Y') gb[i]=true; else gb[i]=false;
        cin>>x;
        if (x=='Y') xb[i]=true; else xb[i]=false;
        cin>>lun[i]; 
     }   
  }
  void zhu()
  {
     int i,j,h,k,l;
     for (l=1;l<=n;l++)
     {
        if (c1[l]>80&&lun[l]>=1) jiang[l]+=8000;
        if (c1[l]>85&&c2[l]>80) jiang[l]+=4000;
        if (c1[l]>90) jiang[l]+=2000;
        if (c1[l]>85&&xb[l]==true) jiang[l]+=1000;
        if (c2[l]>80&&gb[l]==true) jiang[l]+=850;   
     }  
     for (l=1;l<=n;l++) total+=jiang[l];
     max=0;
     for (l=1;l<=n;l++)
     if (max<jiang[l])
     {
        max=jiang[l];
        t=l;  
     }
  }
  void wri()
  {
     cout<<name[t]<<endl<<jiang[t]<<endl<<total<<endl;
  }
    int main()
    {
       init();
       zhu();
       wri(); 
       return 0;
    }

