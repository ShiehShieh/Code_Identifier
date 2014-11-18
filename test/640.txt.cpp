#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

int n;
int maxindex;
int maxschoolar;
int sum;
string name[MAX];
int aveach[MAX];
int avecoop[MAX];
int stduion[MAX];
int westen[MAX];
int lecthor[MAX];
int schoolar[MAX];

void input(){
      cin >> n;
      
      for( int i = 0 ; i < n ; i++ ){
	       cin >> name[i] >>  aveach[i] >>  avecoop[i];
		   char key;
		   cin >> key;
		   
		   if( key == 'Y' ){
		          stduion[i] = 1; 
		   }else{
		          stduion[i] = 0;	 	
		   }
		   
		   cin >> key;
		   
		   if( key == 'Y' ){
		          westen[i] = 1;		
		   }else{
		          westen[i] = 0;	
		   } 
		   
		   cin >>  lecthor[i];
		   
		   schoolar[i] = 0;
		   	     
	  }//end for i	
}

void init(){
      sum = 0;
	  maxindex = 0;
	  maxschoolar = 0;	
}

void judge( int i ){
	    
	    int ans = 0;
	    if( aveach[i] > 80 && lecthor[i] >= 1 ){
		      ans += 8000;
		      sum += 8000;
		    //  cout << name[i] << " " << ans <<endl;
		}
	    
	    if( aveach[i] > 85 && avecoop[i] > 80 ){
		      ans += 4000;
			  sum += 4000;
			 //  cout << name[i] << " " << ans <<endl;	
		}
		
		if( aveach[i] > 90 ){
		      ans += 2000;
			  sum += 2000;	
			 //  cout << name[i] << " " << ans <<endl;
		}  
		
		if( aveach[i] > 85 && westen[i] == 1 ){
		      ans += 1000;
			  sum += 1000;	
			 //  cout << name[i] << " " << ans <<endl;
		}
		
		if( avecoop[i] > 80 && stduion[i] == 1 ){
		      ans += 850;
			  sum += 850;
			  // cout << name[i] << " " << ans <<endl;	
		}
		
		schoolar[i] = ans;
		// cout << name[i] << " " << ans <<endl;
		  
}//end for judge

void output(){
	 
	 for( int i = 0 ; i < n ; i++ ){
          cout << name[i] <<"  " << westen[i] << endl;
	 }
}


int main(){
   
   init();
   input();
   
   
   for(int i=0;i<n;i++)
         judge(i);
   for(int i=0;i<n;i++){
        if( schoolar[i] > maxschoolar ){
		       maxindex = i;
		       maxschoolar = schoolar[i];
		}		
   }      
   
   cout << name[maxindex] << endl;
   cout << schoolar[maxindex] << endl;
   cout << sum << endl;
   
   
   return 0;	
}


