#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

void init_io() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

int main() {
    init_io();

    int t;
    cin >> t;

    ll a, b, n, m, x;
    while (t--) {
        cin >> a >> b >> n >> m;

        x = min(n, m);
        a -= x, b -= x, n -= x, m -= x;

        if (a < 0 || b < 0) {
            cout << "NO" << '\n'; continue;
        }

        if (n == 0 && min(a, b) < m) {
            cout << "NO" << '\n'; continue;
        }

        if (m == 0 && a + b < n) {
            cout << "NO" << '\n'; continue;
        }

        cout << "YES" << '\n';
    }

    return 0;
}