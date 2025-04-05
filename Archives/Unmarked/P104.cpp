#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int x, y;
    while (t--) {
        cin >> x >> y;

        cout << y / (x - 1) << '\n';
    }

    return 0;
}