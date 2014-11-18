#include "stdio.h"
void Max_heapify(int *a,int i,int num)/*保持最大堆性质*/ 
{int l,r,largest,temp; 
l=i*2; 
r=i*2+1; 
if(l<=num&&a[l]<a[i]) 
largest=l; 
else largest=i; 
if(r<=num&&a[r]<a[largest]) 
largest=r; 
if(largest!=i) 
{ 
 temp=a[i]; 
 a[i]=a[largest]; 
 a[largest]=temp; 
 Max_heapify(a,largest,num); 
} 
} 
main()
{int num;
scanf("%d",&num);
int key[num+1];
int i;
for(i=1;i<=num;i++)
scanf("%d",&key[i]);
for(i=num/2;i>0;i--)
Max_heapify(key,i,num);
int end=0;
while(num>1)
{key[0]=key[1];
key[1]=key[num];
key[num]=key[0];
num--;
Max_heapify(key,1,num);
end+=key[1]+key[num+1];
key[1]+=key[num+1];
Max_heapify(key,1,num);
}
printf("%d",end);
}

