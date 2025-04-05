#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int x, y, temp;
    while (t--) {
        cin >> x >> y;

        if (x > y) {
            temp = x;
            x = y;
            y = temp;
        }

        if (y % x == 0) {
            cout << x << '\n';
        } else {
            cout << y % x << '\n';
        }
        
        
    }

    return 0;
}