#include<iostream>
#include<cstdlib>
using namespace std;
int R,C,H[501][501],Data[501][501],
Dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}},Best=0;
void Memory(int X,int Y){
    if(X<1||Y<1||X>R||Y>C)return;
    int i;
    for(i=0;i<4;i++){
                     int FX=X+Dir[i][0],FY=Y+Dir[i][1];
                     if(H[FX][FY]>H[X][Y]&&Data[FX][FY]<=Data[X][Y])
                                          {
                                           Data[FX][FY]=Data[X][Y]+1;
                                           Memory(FX,FY);
                                           }
                     }
}
int main(){
    int i,j;
    cin>>R>>C;
    for(i=1;i<=R;i++)
                     for(j=1;j<=C;j++){
                                      cin>>H[i][j];
                                      Data[i][j]=1;
                                      }
    for(i=1;i<=R;i++)
                     for(j=1;j<=C;j++)
                                       Memory(i,j);
    for(i=1;i<=R;i++)
                     for(j=1;j<=C;j++)                     
                                       Best=max(Data[i][j],Best);
    cout<<Best<<endl;
    return 0;
}

