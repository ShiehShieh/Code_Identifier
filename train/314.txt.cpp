#include<stdio.h>
int main()
{
	long int n,m,f;
	int a[32]={0},b[32]={0},i=0,j,k,c;
	scanf("%ld",&n);
	 if(n==0||n==1)printf("%d\n",n+1);
	 else{
	       while(i<32)//十进制转化成二进制，按二进制的倒序存储
		   {
			  
			   
	         a[i]=n%2;
	    	n=n/2;
		    i++;
	     	if(n==1)
			{
		       	a[i]=1;
			    break;
			}
		   }
           c=i;
        	b[c]=a[c];
        	for(k=c;k>=0;k--)
			{
	        	b[k-1]=b[k]^a[k-1];//二进制转化成格雷码
			}
          /*	for(j=c;j>=0;j--)
	        	printf("%d",b[j]);
                printf("\n");
           */
	         f=1;
          	m=0;
         	for(j=0;j<=c;j++)
			{
	       	m=m+b[j]*f;//将格雷码看成二进制数换算成十进制数字
	        	f=f*2;
			}
        	printf("%ld\n",m+1);
	 }
return 0;
	
}

	
