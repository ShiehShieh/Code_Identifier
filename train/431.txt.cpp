#include <iostream>
using namespace std;

struct triple {
    long long d, x, y;
};


long long mod(long long a, long long b) {
    if (a >= 0)
        return a % b;
    else
        return a % b + b;
}

triple Extended_Euclid(long long a, long long b) {
    triple result;
    if (b == 0) {
        result.d = a;
        result.x = 1;
        result.y = 0;
    }
    else {
        triple ee = Extended_Euclid(b, mod(a, b));
        result.d = ee.d;
        result.x = ee.y;
        result.y = ee.x - (a / b) * ee.y;
    }
    return result;
}

/* 
 * ax = b (mod n)
 */
long long MLES(long long a, long long b, long long n) {
    triple ee = Extended_Euclid(a, n);
    if (mod(b, ee.d) == 0) 
        return mod(ee.x * (b / ee.d), n / ee.d);
    else return -1;
}

int main() {

    long long x, y, m, n, l;
    long long a, b, result;

    cin >> x >> y >> m >> n >> l;

    x %= l; y %= l;
    m %= l; n %= l;

    a = m - n; 
    b = y - x;

    if (a < 0) {
        a = -a;
        b = -b;
    }
    while (b < 0) b += l;

    result = MLES(a, b, l);

    if (result < 0)
        cout << "Impossible" << endl;
    else
        cout << result << endl;

    return 0;
}
