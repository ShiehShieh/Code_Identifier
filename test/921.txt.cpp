#include <iostream>

using namespace std;

int a , b;

int main(){
	
	cin >> a >> b;
	int num[a+1];
	int judge[a+1];
	for(int i=1;i<=a;i++){
	      cin >> num[i];
		  judge[i] = num[i] * i;	
	}
	
	int index;
	
	for(int i=1;i<=a;i++){
	      for(int j=i+1;j<=a;j++){
		      if( num[i]*i == num[j]*j ){
			        index = (i+j)/2;		
			  }
		  }
	}
	
	int ans = 0;
	
	if( b == 0 ){
		
		for(int i=1;i<=index;i++)
	 	       ans += num[i];
	}else{	
        for(int i=a;i>=index;i--){
		       ans += num[i];	
		}
	}
	
	cout << index << " " << ans << endl;
	
	return 0;
}
