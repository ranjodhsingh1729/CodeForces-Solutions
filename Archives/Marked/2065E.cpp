#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll MOD = 1e9+7;
const int MAXN = 1e6+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    if (abs(n-m) > k || max(n,m) < k) {
        cout << -1 << '\n'; return;
    }

    ll a, b, f;
    f = n < m;
    a = min(n, m);
    b = max(n, m);

    for (int i = 0; i < k; i++) {
        cout << (f ? "1" : "0");
    }
    b -= k;
    while (a||b) {
        if (a && b) {
            cout << (f ? "01" : "10");
            a--; b--;
        } else {
            if (a) {
                cout << (f ? 0 : 1);
                a--;
            } else {
                cout << (f ? 1 : 0);
                b--;
            }
        }
    }

    cout << '\n';
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}