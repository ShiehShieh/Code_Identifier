#include<iostream.h>
int gg[10000],year,month,day,n,i;
bool pd()
{
     if (month==9&&day==30) return true;
     if (month==11&&day==30) return true;
     if ((month+day)%2==0) return true;
     return false;
}
int main()
{
  cin>>n;
  for (i=1;i<=n;i++) 
   {cin>>year>>month>>day;
    gg[i]=pd();}
  for (i=1;i<=n;i++)
   if (gg[i]==true) cout<<"YES"<<endl;
                  else cout<<"NO"<<endl;    
}

