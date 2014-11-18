#include <iostream>
using namespace std;
int num=0;
struct ship{
__int64 start;
__int64 end;
}ships[20000],current;

struct ship Unite(struct ship,struct ship);
void QuickSort(int first,int end);
int Partition(int first,int end);
int main()
{
int N;
cin >> N;
__int64 a,b;
for(int i=0;i<N;i++)
{
 cin >> a >> b;
 if(a!=b)
 {
ships[num].start=a;
ships[num].end=b;
num++;
 }
}
QuickSort(0,num-1);
/*for(int i=0;i<num;i++)
 cout << ships[i].start << '~' << ships[i].end << endl;*/
 
__int64 length=0;
current=ships[0];
for(int i=1;i<num;i++)
{
 if(ships[i].start>current.end)
 {
length+=(current.end-current.start);
current=ships[i];
 }
 else current=Unite(current,ships[i]);
}
length+=(current.end-current.start);
cout << length << endl;
return 0;
}

struct ship Unite(struct ship a,struct ship b)
{
struct ship c;
c.start=min(a.start,b.start);
c.end=max(a.end,b.end);
return c;
}

void QuickSort(int first,int end)
{
if(first<end)
{
 int pivot=Partition(first,end);
 QuickSort(first,pivot-1);
 QuickSort(pivot+1,end);
}
}
int Partition(int first,int end)
{
int i=first,j=end;
while(i<j)
{
 while(i<j&&ships[i].start<=ships[j].start) j--;
 if(i<j)
 {
swap(ships[i],ships[j]);
i++;
 }
 while(i<j&&ships[i].start<=ships[j].start) i++;
 if(i<j)
 {
swap(ships[j],ships[i]);
j--;
 }
}
return i;
}
