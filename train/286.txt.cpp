#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Point {
       int x,y;
       }a,b,c,d;
int crsprd(Point s,Point u,Point v){
    return (u.x-s.x)*(v.y-s.y)-(v.x-s.x)*(u.y-s.y);
    }
int dotprd(Point s,Point u,Point v){
    return (u.x-s.x)*(v.x-s.x)+(u.y-s.y)*(v.y-s.y);
    }
double length(Point u,Point v){
    return sqrt(double((v.x-u.x)*(v.x-u.x)+(v.y-u.y)*(v.y-u.y)));  
    }
bool cross(Point a,Point b,Point c,Point d){
     if(crsprd(a,b,c)*crsprd(a,b,d)>=0)return false;
     if(crsprd(c,d,a)*crsprd(c,d,b)>=0)return false;
     return true;
     }
int main(){
    double len,tmp;
    scanf("%d %d",&a.x,&a.y);
    scanf("%d %d",&b.x,&b.y);
    scanf("%d %d",&c.x,&c.y);
    scanf("%d %d",&d.x,&d.y);
    if(cross(a,b,c,d))printf("0.0000\n");
    else {
         len=32767;
         tmp=(double)abs(crsprd(a,b,c))/length(a,b);
         if(len>tmp&&dotprd(a,b,c)>=0&&dotprd(b,a,c)>=0)len=tmp;
         tmp=(double)abs(crsprd(a,b,d))/length(a,b);
         if(len>tmp&&dotprd(a,b,d)>=0&&dotprd(b,a,d)>=0)len=tmp;
         tmp=(double)abs(crsprd(c,d,a))/length(c,d);
         if(len>tmp&&dotprd(c,d,a)>=0&&dotprd(d,c,a)>=0)len=tmp;
         tmp=(double)abs(crsprd(c,d,b))/length(c,d);
         if(len>tmp&&dotprd(c,d,b)>=0&&dotprd(d,c,b))len=tmp;
         tmp=length(a,c);
         if(tmp<len)len=tmp;
         tmp=length(a,d);
         if(tmp<len)len=tmp;
         tmp=length(b,c);
         if(tmp<len)len=tmp;
         tmp=length(b,d);
         if(tmp<len)len=tmp;
         printf("%0.4lf\n",len);
         }
    return 0;
    }
