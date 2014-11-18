#include <iostream>
using namespace std;
int n,k;
int a[300];
int b[300][300];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		while(cin>>x&&x!=0){
			if(x!=i){
				a[i]++;
				b[i][a[i]]=x;
			}
		}
	}
	int m=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=k) m++;
	}
	cout<<m<<endl;
	return 0;
}
