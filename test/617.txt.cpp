#include<cstdio>
#include<math.h>
long n,i,j,x,y,map[30001];
long double opin,res,num,p;
void Swap(int i,int j){
     int p;
     p=map[i];
     map[i]=map[j];
     map[j]=p;
     }
void Sift(int below,int len){
     int h;
     while(below*2<=len){
                         if(below*2==len)                     h=below*2;
                         else if(map[below*2]>map[below*2+1]) h=below*2;
                         else                               h=below*2+1;
                         if(map[h]<=map[below]) break;
                         Swap(below,h);
                         below=h; 
                         }
     return;
     }
void Heap(){
     int v,k;
     for(v=n/2;v>0;v--) Sift(v,n);
     for(v=n;v>1;v--){
                      Swap(1,v);
                      Sift(1,v-1);
                      }
     }
int main(){
    opin=1000000.0;
    res=0.6180339887498949;
    scanf("%ld",&n);
    for(i=1;i<=n;i++){
                      scanf("%ld",&map[i]);
                      if(map[i]==0) i--,n--;
                      }
    Heap();
    i=1;j=2;
    while(j<=n){
                p=((double)map[i])/((double)map[j]);
                num=p-res;
                if(num<0) num*=-1;
                if(num<opin){
                             x=i;
                             y=j;
                             opin=num;
                             }
                if(p<res){
                          i++;
                          if(i==j) j++;
                          }
                else j++;
            }
    printf("%d\n%d\n",map[x],map[y]);
    return 0;
} 

