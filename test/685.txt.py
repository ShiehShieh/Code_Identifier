#include "queue"
#include "iostream"
//priority_queue

using namespace std;

int main()
{
	priority_queue<int,std::vector<int>,greater<int> > p;
	int n;
	int r;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>r;
		p.push(r);
	}
	int s=0;
	while(true)
	{
		int r=p.top();
		p.pop();
		if(p.empty()){
			cout<<s;
			return 0;
		}
		p.push(r+p.top());
		s+=r+p.top();
		p.pop();
	}
	return 0;
}
