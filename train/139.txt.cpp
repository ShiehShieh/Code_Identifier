#include <iostream>
#include <string>
using namespace std;
const int MaxN = 100;
struct student
{
       string name;
       int grade;
       int assessment;
       bool student_leader;
       bool western;
       int thesis;
};
int n;
student a[MaxN];
int prize[MaxN] = {0};
void init();
void doit();

int main()
{
    init();
    doit();
    return 0;
}
void init()
{
      cin >> n;
      char ch;
      for (int i = 0; i < n; i++)
      {
          cin >> a[i].name
              >> a[i].grade >> a[i].assessment;
          cin >> ch;
          if (ch == 'Y') a[i].student_leader = true;
          else a[i].student_leader = false;
          cin >> ch;
          if (ch == 'Y') a[i].western = true;
          else a[i].western = false;
          cin >> a[i].thesis;
      }
}
void doit()
{
     for (int i = 0; i < n; i++)
     {
         if ((a[i].grade > 80) && (a[i].thesis >= 1))
            prize[i] += 8000;          // 院士奖学金
         if ((a[i].grade > 85) && (a[i].assessment > 80))
            prize[i] += 4000;          // 五四奖学金
         if (a[i].grade > 90) 
            prize[i] += 2000;          // 成绩优秀奖
         if ((a[i].grade > 85) && (a[i].western)) 
            prize[i] += 1000;          // 西部奖学金
         if ((a[i].assessment > 80) && (a[i].student_leader))
            prize[i] += 850; 
     }
     int most = 0;
     int num = 0;
     int sum = 0;
     for (int i = 0; i < n; i++)
     {
         sum += prize[i];
         if (prize[i] > most)
         {
            most = prize[i];
            num = i;
         }
     }
     cout << a[num].name << endl;
     cout << most << endl;
     cout << sum << endl;
}

