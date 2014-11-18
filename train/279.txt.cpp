#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a[9],x;
for(int i=0;i<9;i++)
   cin>>a[i];
for (int i0=0;i0<4;i0++)
for (int i1=0;i1<4;i1++)
for (int i2=0;i2<4;i2++)
for (int i3=0;i3<4;i3++)
for (int i4=0;i4<4;i4++)
for (int i5=0;i5<4;i5++)
for (int i6=0;i6<4;i6++)
for (int i7=0;i7<4;i7++)
for (int i8=0;i8<4;i8++){
int b[9];
b[0]=(a[0]+i0+i1+i3)%4;
b[1]=(a[1]+i0+i1+i2+i4)%4;
b[2]=(a[2]+i1+i2+i5)%4;
b[3]=(a[3]+i0+i3+i4+i6)%4;
b[4]=(a[4]+i0+i2+i4+i6+i8)%4;
b[5]=(a[5]+i2+i4+i5+i8)%4;
b[6]=(a[6]+i3+i6+i7)%4;
b[7]=(a[7]+i4+i6+i7+i8)%4;
b[8]=(a[8]+i5+i7+i8)%4;
int t=0;
for (int i=0;i<9;i++)
  if (!b[i]) t++;
string ans="";
if (t==9) {
for (int k=1;k<=i0;k++) ans+="1 ";
for (int k=1;k<=i1;k++) ans+="2 ";
for (int k=1;k<=i2;k++) ans+="3 ";
for (int k=1;k<=i3;k++) ans+="4 ";
for (int k=1;k<=i4;k++) ans+="5 ";
for (int k=1;k<=i5;k++) ans+="6 ";
for (int k=1;k<=i6;k++) ans+="7 ";
for (int k=1;k<=i7;k++) ans+="8 ";
for (int k=1;k<=i8;k++) ans+="9 ";
ans[ans.length()-1]='\n';
cout<<ans;
return 0;
}
}
return 0;
}
