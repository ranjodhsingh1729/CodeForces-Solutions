#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n;
    cin >> n;
    vector <int> via(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> via[i];
    }

    bool f = 1;
    ll x = 1;
    for (int i = 1; i <= min(21, n); i++) {
        x = lcm(x, i+1);
        if (via[i] % x == 0) {
            f = 0;
            break;
        }
    }

    cout << (f ? "YES" : "NO") << '\n';
}


int main() {
    FIXIO;

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}