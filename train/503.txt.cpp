#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> se;
    int n, i, x;
    while (scanf("%d", &n) != EOF) {
        se.clear();
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            se.insert(x);
        }
        n = 0;
        multiset<int>::iterator p;
        x = 0;
        for (p = se.begin(); p != se.end(); p++) {
            if (x == 0)x = *p;
            else x += *p, se.insert(x), n += x, x = 0;
        }
        printf("%d\n", n);
    }
    return 0;
}

