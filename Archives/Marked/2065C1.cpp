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
    ll n, m;
    cin >> n >> m;
    vector <int> via(n);
    vector <int> vib(m);
    for (int i = 0; i < n; i++) {
        cin >> via[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> vib[i];
    }

    int x = vib[0], f = 1, tmp;
    via[0] = min(via[0], x-via[0]);
    for (int i = 1; i < n; i++) {
        if (via[i] < via[i-1] && x-via[i] < via[i-1]) {
            f = 0; break;
        }
        if (x-via[i] >= via[i-1]) {
            if (via[i] >= via[i-1])
                via[i] = min(via[i], x-via[i]);
            else
                via[i] = x-via[i];
        }
    }

    if (f) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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