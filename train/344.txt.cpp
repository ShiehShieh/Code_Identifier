//合并果子 By Mr.Tao
#include <iostream>
#define MAX 40000
using namespace std;

long n;
long a[2*MAX+1];
void qsort (long st, long ed) {
	long i = st, j = ed, x = a[(long) (st+ed)/2], y;
	while (i <= j) {
		while (a[i] < x) ++i;
		while (x < a[j]) --j;
		if (i <= j)
			{
				y = a[i];
				a[i] = a[j];
				a[j] = y;
				++i; --j;
			}
	}
	if (i < ed) qsort(i, ed);
	if (st < j) qsort(st, j);
return;
}

int
main (void) {
		cin >> n;
		for (long i = 0; i < n; ++i) { 
			cin >> a[i]; }
		if ( n <= 1 ) cout << a[0] << endl;
		else {
			qsort ( 0, n-1 );
			long i = 0, k, j1 = 2*n, j2 = j1;
			long min[2], sum = 0;
			for (long m = 1; m < n; ++m) {
                for ( k = 0; k < 2; ++k) {
                    if ( i < n && a[i] <= a[j1] || j1 >= j2)
                      { min[k] = i++; }
                    else
                    if ( j1 < j2 )
                      { min[k] = j1++; }
                    else
                      { min[k] = i++; }
                }
                a[j2] = a[min[0]] + a[min[1]];
                sum += a[j2];
                j2++;
                
                /*
				if ( i + 1 < n && a[i] + a[i+1] <= a[i] + b[j1])
					{ b[j2] = a[i] + a[i+1]; ++j2; i+=2; }
				else 
					{ b[j2] = a[i] + b[j1]; ++j2; ++j1; ++i; }
					*/
			}
//			for ( i = 0; i < j2; ++i) {
//				sum += b[i]; }
			cout << sum << endl;
		}
return 0;
}

