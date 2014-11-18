#include <iostream>
#include <string>
using namespace std;
int top=0,n;
struct node{
       int x1,y1,x2,y2;
}stack[100];
void Open(int x1,int y1,int x2,int y2){
     stack[top].x1=x1;stack[top].y1=y1;stack[top].x2=x2;stack[top].y2=y2;
     top++;
}
void Click(int x,int y){
     int i=top-1,j;
     while (i>=0&&!(x>=stack[i].x1&&x<=stack[i].x2&&y>=stack[i].y1&&y<=stack[i].y2)) i--;
     if(i<0) return;
     node k=stack[i];
     for (j=i;j<top-1;j++) stack[j]=stack[j+1];
     stack[top-1]=k;
}
void Clit(int x,int y){
     int i=top-1,j;
     while (i>=0&&!(x>=stack[i].x1&&x<=stack[i].x2&&y>=stack[i].y1&&y<=stack[i].y2)) i--;
     if(i<0) return;
     for (j=i;j<top-1;j++) stack[j]=stack[j+1];
     top--;
}
void Move(int x,int y,int a,int b){
     int i=top-1,j;
     while (i>=0&&!(x>=stack[i].x1&&x<=stack[i].x2&&y>=stack[i].y1&&y<=stack[i].y2)) i--;
     if(i<0) return;
     stack[i].x1+=a;stack[i].x2+=a;
     stack[i].y1+=b;stack[i].y2+=b;
}
int main(){
    cin>>n;
    int i,a,b,c,d;
    string s;
    for (i=1;i<=n;i++){
        cin>>s;
        if(s=="Open") {cin>>a>>b>>c>>d;Open(a,b,c,d);}
        else if(s[3]=='s') {cin>>a>>b;Clit(a,b);}
        else if(s=="Click") {cin>>a>>b;Click(a,b);}
        else {cin>>a>>b>>c>>d;Move(a,b,c,d);}
        /*for (a=0;a<top;a++) cout<<"x1="<<stack[a].x1<<" y1="<<stack[a].y1<<" x2="<<stack[a].x2<<" y2="<<stack[a].y2<<endl;
        cout<<endl;*/
    }
    if(top==0) cout<<"Nothing";
    else cout<<stack[top-1].x1<<' '<<stack[top-1].y1<<' '<<stack[top-1].x2<<' '<<stack[top-1].y2;
    //while(1);
    return 0;
}
