#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = 0x3f3f3f3f3f3f3f3f;

void fileio() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

ll fact(ll x) {
    ll y = 1;
    for (int i = x; i > 1; i--) {
        y = (y * i) % MOD;
    }
    return y;
}

void solve() {
    string x;
    cin >> x;
    int n = x.size();

    ll a, b;
    a = 0; b = 1;

    int c = 1;
    for (int i = 1; i < n; i++) {
        if (x[i] != x[i-1]) {
            a += c-1;
            b = (b * c) % MOD;

            c = 1;
        } else {
            c++;
        }
    }

    a += c-1;
    b = (b * c) % MOD;
    b = ((b % MOD) * (fact(a) % MOD)) % MOD;

    cout << a << ' ' << b << '\n';
}


int main() {
    FIXIO;
    //fileio();

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}