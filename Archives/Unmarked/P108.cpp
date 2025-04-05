#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int x, y, temp;
    while (t--) {
        cin >> x >> y;

        while (x != 0) {
            if (x > y) {
                temp = x;
                x = y;
                y = temp;
            }

            temp = x;
            x = y % x;
            y = temp;
        }

        cout << y << '\n';
    }

    return 0;
}