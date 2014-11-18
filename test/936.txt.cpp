#include <iostream>

using namespace std;

const int MAX = 32767;

long long num[MAX+1];

long long n;

int main(){
	
	cin >> n;
	num[0] = 0;
    
    for(int i=1;i<=n;i++){
         num[i] = i*i + num[i-1];
	}//end for i
	
	cout << num[n] << endl;
	
   
    return 0;	
}

