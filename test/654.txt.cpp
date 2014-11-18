#include<iostream>
using namespace std;
int main(){
	double P,Q,p,q;
	double i,count;
	double k;
	cin >> P >> Q;
	i=1;
	p=P/100;
	q=Q/100;
		for(count=1;;count++){
			k=i/count;
			if(k>p&&k<q){cout << count<<endl;break;}
			else if(k<p){i++;count=i;}
		}
		return 0;
}

