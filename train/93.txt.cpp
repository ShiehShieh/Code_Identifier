#include<iostream>
using namespace std;
int cmp(const void*a,const void*b)
	{  return *(int*)a-*(int*)b; 
	} 
main()
{  int i,j,n,a[10000],sum=0;
   cin>>n;
   for(i=0;i<n;i++)
   		cin>>a[i];
   qsort(a,n,sizeof(int),cmp);
   for(i=1;i<n;i++)
  	  {	  if(a[i-1]<=a[i]) //符合原则 处理 
		    	{ a[i]+=a[i-1];
		  	      sum+=a[i]; 
			    }		
	  	  else {  a[i]^=a[i-1]; 
				  a[i-1]^=a[i];
				  a[i]^=a[i-1];	
			      for(j=i;j<n;j++)
			      	{  if(a[j]<=a[j+1]||j==n-1)//第二次排序完毕,或已到末尾 
			      		  {  a[i]+=a[i-1];
		  	        		 sum+=a[i];
		  	        		 break;
						  } 
					  else { a[j]^=a[j+1];
					     	 a[j+1]^=a[j];	
					         a[j]^=a[j+1];
						   } 
					}
			
			   }			 
      }
cout<<sum<<endl;
}
