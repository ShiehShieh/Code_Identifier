#include <iostream>

using namespace std;

const int MAX = 1000;

long n , k , f , length[ MAX + 10 ];

int main(){
	
	long a , b , i , carry , ans;
	
	cin >> n >> k >> f;
	
	for(i=1;i<=n;i++)
	     length[i] = 1;
	for(i=1;i<=f;i++){
          cin >> a >> b;
          length[a] += b;
	}
	
	ans = 1;
	carry = 0;
	
	for(i=1;i<=n;i++){
          if( carry+length[i] > k ){
		         ans++;
				 carry = length[i];		
		  }else{
		        carry += length[i];		
		  }
	}
	
	cout << ans << endl;
	 
	
	return 0;
}
