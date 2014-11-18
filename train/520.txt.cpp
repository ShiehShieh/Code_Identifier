#include<iostream>
#include<cmath>
using namespace std;

struct point {
    double x, y;
} p[810];
double d[810][810];
double dt[810];
bool used[801];

double dis(point p1, point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
}

int main() {
    int i, n, t, j, now;
    double ans = 0, min;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
    for (i = 1; i <= n; i++)
        for (j = 1; j < i; j++)
            d[j][i] = d[i][j] = dis(p[i], p[j]);
    for (i = 1; i <= n; i++) dt[i] = d[1][i];
    used[1] = 1;
    for (i = 1; i <= n - 1; i++) {
        min = 1000000;
        now = -1;
        for (j = 1; j <= n; j++)
            if (!used[j] && dt[j] < min) {
                min = dt[j];
                now = j;
            }
        used[now] = 1;
        ans += min;
        for (j = 1; j <= n; j++)
            if (!used[j] && dt[j] > d[now][j])
                dt[j] = d[now][j];
    }
    printf("%.3lf\n", ans);
    return 0;
}
