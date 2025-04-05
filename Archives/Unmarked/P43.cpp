#include <bits/stdc++.h>

#define echolock(a, b, c, d) (cout << a << ' ' << b << ' ' << c << ' ' << d << '\n')

using namespace std;

int main() {
    int d;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 != x2 && y1 != y2 && (abs(x2 - x1) != abs(y2 - y1))) {
        cout << -1 << '\n'; return 0;
    }

        
    if (x1 == x2) {
        d = y2 - y1;

        if (x1 + d > 1000 || x2 + d > 1000) {
            echolock(x1 - d, y1, x2 - d, y2);
        } else {
            echolock(x1 + d, y1, x2 + d, y2);
        }

    } else if (y1 == y2) {
        d = x2 - x1;

        if (y1 + d > 1000 || y2 + d > 1000) {
            echolock(x1, y1 - d, x2, y2 - d);
        } else {
            echolock(x1, y1 + d, x2, y2 + d);
        }

    } else {
        d = round(sqrt(pow(abs(y2-y1), 2) + pow(abs(x2-x1), 2)) / sqrt(2));

        if (y2 > y1 && x2 > x1)
            echolock(x1 + d, y1, x1, y1 + d);
        if (y2 < y1 && x2 < x1) 
            echolock(x1 - d, y1, x1, y1 - d);
        if (y2 > y1 && x2 < x1)
            echolock(x1 - d, y1, x1, y1 + d);
        if (y2 < y1 && x2 > x1)
            echolock(x1 + d, y1, x1, y1 - d);
    }

    return 0;
}