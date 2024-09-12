#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n;
    while (t--) {
        cin >> n;

        int x = 1;
        int y = n % 2 ? n - 1 : n;
        for (int i = 0; i < n/2; i++) {
            cout << y << ' ';
            y -= 2;
            cout << x << ' ';
            x += 2;
        }
        if (x == n) cout << x << ' ';

        cout << '\n';
    }

    return 0;
}