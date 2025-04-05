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

    ll t;
    cin >> t;

    ll x, y, k;
    while (t--) {
        cin >> x >> y >> k;

        if (k % 2) {
            cout << x << ' ' << y << '\n';
        }

        for (int i = 1; i <= k/2; i++) {
            cout << x+i << ' ' << y+i << '\n';
            cout << x-i << ' ' << y-i << '\n';
        }
        
    }

    return 0;
}