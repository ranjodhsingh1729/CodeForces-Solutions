#include <bits/stdc++.h>

#define MAXLEN 100000

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;

    ll k, x, a;
    while (t--) {
        cin >> k >> x >> a;

        ll i, y, d = 0;
        for (i = 0; a > 0 && i < x; i++) {
            y = floor((double) d / (double) (k - 1)) + 1;

            if (y < a) {
                a -= y;
                d += y;
            } else {
                break;
            }
        }


        if (i == x && a*(k-1) > d) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        
    }

    return 0;
}