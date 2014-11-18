#include <iostream>
#define FOR(i,a,b) for(i=a;i<b;i++)
using namespace std;
     int Start(0) , end ;
     int k , m ;  //m是循环变量，k为设置宽度
     char num [200];

     void Minus()  //打印横杠'-'
        {
         cout << ' ';
         for ( m = 0 ; m < k ; m++ ) cout << '-' ;
         cout << ' ';
        }
     void Shu(bool left,bool right) //打印竖线'|'
        {
         if (left)  cout << '|';
         else       cout << ' ';
         for ( m = 0 ; m < k ; m++ ) cout << ' ' ;
         if (right) cout << '|';
         else       cout << ' ';
        }

int main(){
    int i , j ;
    cin >> k >> num ;
    short int n[end = strlen(num)];
    end -- ;
    for ( i = Start ; i <= end ; i++ )
                                   n[i] = (int)num[i] - 48;
//打印第一部分
    for ( i = Start ; i <= end ; i++ ) //n[i]是打印的第i个数
         {
          if (n[i] != 1 && n[i] !=4 ) Minus() ;  //只有1和4上面没有横杠
          else                                   //当n[i]是1或4时
              for ( j = 0 ; j < k + 2 ; j++ ) cout << ' ';
          if ( i < end ) cout << ' ' ;
         }
          cout << endl ;
//打印第2部分
    for ( i = 0 ; i < k ; i++ )
        {
         for ( j = Start ; j <= end ; j++ )
           {
            if (n[j] == 1 || n[j] == 2 || n[j] == 3 || n[j] == 7) Shu(0,1) ;
            else if (n[j] == 5 || n[j] == 6) Shu(1,0);
            else Shu(1,1);
            if ( j < end ) cout << ' ' ;
           }
            cout << endl;
        }
//打印第3部分
    for ( i = Start ; i <= end ; i++ )
         {
          if (n[i] ==7 || n[i] == 0 )
              for ( j = 0 ; j < k + 2 ; j++ ) cout << ' ' ;
          else if ( n[i] == 1 )
                       for ( j = 0 ; j < k + 2 ; j++ ) cout << ' ';
          else Minus();
          if ( i < end ) cout << ' ' ;
         }
         cout << endl;
//打印第4部分
    for ( i = 0 ; i < k ; i++ )
        {
         for ( j = Start ; j <= end ; j++ )
           {
            if (n[j] == 6 || n[j] == 8 || n[j] == 0 ) Shu(1,1);
            else if (n[j] == 2) Shu(1,0);
            else Shu(0,1);
            if ( j < end ) cout << ' ' ;
           }
          cout << endl;
        }
//打印第5部分
    for ( i = Start ; i <= end ; i++ )
         {
          if ( ( n[i] == 1 ) || ( n[i] == 4 ) || ( n[i] == 7 ) )
                 for ( j = 0 ; j < k + 2 ; j++ ) cout << ' ' ;
          else Minus();
          if ( i < end )cout << ' ' ;
         }
         cout << endl;
}
