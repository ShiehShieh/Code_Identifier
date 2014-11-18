#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct {
int x,y,price;
}peanut;
const int maxn = 20;
void swap(int &x,int &y) {
int t = x;
x = y;
y = t;
}
int main() {
int n = 0,x,y,t,i,j,temp,num = 0,price = 0;
peanut dat[maxn*maxn];
memset(dat,0,sizeof(peanut)*maxn*maxn);
cin >> x >> y >> t;
for (i = 0;i < x;i++)
for (j = 0;j < y;j++) {
cin >> temp;
if (temp > 0) {
dat[n].price = temp;
dat[n].x = i + 1;
dat[n++].y = j + 1;
}
}
for (i = 0;i < n-1;i++) {
bool flag = false;
for (j = 0;j < n-i-1;j++)
if (dat[j].price < dat[j+1].price) {
flag = true;
swap(dat[j].price,dat[j+1].price);
swap(dat[j].x,dat[j+1].x);
swap(dat[j].y,dat[j+1].y);
}
if (!flag)
break;
}
temp = n; t -= 2; x = 1; y = dat[0].y;
while (num < temp) {
if (t - abs(dat[num].x - x) - abs(dat[num].y - y) - abs(dat[num].x - 1) - 1>= 0) {
t -= (abs(dat[num].x - x) + abs(dat[num].y - y) + 1);
x = dat[num].x;
y = dat[num].y;
price += dat[num].price;
num++;
}
else
break;
}
cout << price << endl;
return 0;
}

