#include <iostream>
#define FOR(i,a,b) for(i=a;i<b;i++)
using namespace std;
struct Student
{
char name[21];
int m1,m2;
char c1,c2;
int p,total;
};
int main( void )
{
int n,i,totals(0),max(0);
cin >> n;
struct Student* team = new Student[n],* tmax ;
FOR(i,0,n) {
cin >> team[i].name
>> team[i].m1 >> team[i].m2
>> team[i].c1 >> team[i].c2
>> team[i].p;
team[i].total = 0;
}
FOR(i,0,n) {
if (team[i].m1 > 80 && team[i].p > 0) team[i].total += 800;
if (team[i].m1 > 85 && team[i].m2 > 80) team[i].total += 400;
if (team[i].m1 > 90) team[i].total += 200;
if (team[i].m1 > 85 && team[i].c2 == 'Y') team[i].total += 100;
if (team[i].m2 > 80 && team[i].c1 == 'Y') team[i].total += 85;
totals += team[i].total;
}
max = team[0].total; tmax = &team[0];
FOR(i,1,n) if (team[i].total > max)
{max = team[i].total ; tmax = &team[i]; }
cout << tmax -> name << endl
<< tmax -> total << '0' << endl
<< totals << '0' << endl;
totals = max = 0;
delete [] team;
}

