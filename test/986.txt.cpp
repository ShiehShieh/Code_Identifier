
#include<iostream>

using namespace std;
int clock1[3][3];
int clock2[3][3];
int main()
{

    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {cin>>clock1[i][j];//clock1[i][j]/=3;
    }
    int i0,i1,i2,i3,i4,i5,i6,i7,i8;
    for(i0=0;i0<4;i0++)
    for(i1=0;i1<4;i1++)
    for(i2=0;i2<4;i2++)
    for(i3=0;i3<4;i3++)
    for(i4=0;i4<4;i4++)
    for(i5=0;i5<4;i5++)
    for(i6=0;i6<4;i6++)
    for(i7=0;i7<4;i7++)
    for(i8=0;i8<4;i8++)
    {
            memcpy(clock2,clock1,sizeof(clock1));
            clock2[0][0]+=i0+i1+i3;clock2[0][0]%=4;
            clock2[0][1]+=i0+i1+i2+i4;clock2[0][1]%=4;
            clock2[0][2]+=i1+i2+i5;clock2[0][2]%=4;
            clock2[1][0]+=i0+i3+i4+i6;clock2[1][0]%=4;
            clock2[1][1]+=i0+i2+i4+i6+i8;clock2[1][1]%=4;
            clock2[1][2]+=i2+i4+i5+i8;clock2[1][2]%=4;
            clock2[2][0]+=i3+i6+i7;clock2[2][0]%=4;
            clock2[2][1]+=i4+i6+i7+i8;clock2[2][1]%=4;
            clock2[2][2]+=i5+i7+i8;clock2[2][2]%=4;
            bool f=false;
            for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)if(clock2[i][j]!=0)f=true;
            if(!f)
            {
                  string ans;
                  for(int i=0;i<i0;i++)ans+="1 ";
                  for(int i=0;i<i1;i++)ans+="2 ";
                  for(int i=0;i<i2;i++)ans+="3 ";
                  for(int i=0;i<i3;i++)ans+="4 ";
                  for(int i=0;i<i4;i++)ans+="5 ";
                  for(int i=0;i<i5;i++)ans+="6 ";
                  for(int i=0;i<i6;i++)ans+="7 ";
                  for(int i=0;i<i7;i++)ans+="8 ";
                  for(int i=0;i<i8;i++)ans+="9 ";
                  ans[ans.length()-1]='\n';
                  cout<<ans;
                  break;
            }
    }
    
    //cout<<endl;
    //cin>>i0;
    return 0;
}

