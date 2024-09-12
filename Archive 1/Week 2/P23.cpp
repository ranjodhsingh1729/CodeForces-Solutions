#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, k;
    while (t--) {
        cin >> n >> k;

        cout << ( k != (4*n - 2) ? (k + 1)/2 : (k + 2)/2 ) << '\n';
    }

    return 0;
}