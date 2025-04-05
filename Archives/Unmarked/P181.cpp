#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

ll solve(ll n, ll m, ll x, ll y, ll l) {
    return ((n - x)/l + (x - 1)/l + 1) * ((m - y)/l + (y - 1)/l);
}

int main() {
    int t;
    cin >> t;

    ll n, m, l, x, y;
    while (t--) {
        cin >> n >> m >> x >> y >> l;

        cout << ((n - x)/l + (x - 1)/l + 1) * ((m - y)/l + (y - 1)/l + 1) << '\n';
    }

    return 0;
}