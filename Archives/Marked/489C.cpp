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
    ll m, s;
    cin >> m >> s;

    if (m == 1 && s == 0) {
        cout << 0 << ' ' << 0 << '\n'; return;
    }
    if (s > 9*m || !s && m>1) {
        cout << -1 << ' ' << -1 << '\n'; return;
    }

    vector <int> via(m+1, 0);
    vector <int> vib(m+1, 0);
    int nines = s/9;
    for (int i = 0; i < nines; i++) {
        via[i] = 9;
    }
    via[nines] = s%9;

    vib[0] = max(1, s-9*(m-1));
    for (int i = m-1, x = s-vib[0]; x && i >= 0; i--) {
        if (x >= 9) {
            x -= 9;
            vib[i] = 9;
        } else {
            vib[i] = x;
            x = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << vib[i];
    }
    cout << ' ';
    for (int i = 0; i < m; i++) {
        cout << via[i];
    }
    cout << '\n';

}


int main() {
    FIXIO;

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}