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
    ll n, x, k;
    cin >> n >> x >> k;
    string commands;
    cin >> commands;
    int m = commands.size();

    ll i, sum = 0, sumi = -1;
    for (i = 1; i <= m; i++) {
        sum += (commands[i-1] == 'R' ? 1 : -1);
        if (sum == 0) break;
    }
    if (sum == 0) {
        sumi = i;
    }


    ll cur = x, curi = -1;
    for (i = 1; i <= m; i++) {
        cur += (commands[i-1] == 'R' ? 1 : -1);
        if (cur == 0) break;
    }
    if (cur == 0) {
        curi = i;
    }

    // cout << curi << ' ' << sumi << "\n";

    if (curi == -1) {
        cout << 0 << '\n';
        return;
    }

    if (k < curi) {
        cout << 1 << '\n';
        return;
    }

    if (sumi == -1) {
        cout << 1 << '\n';
        return;
    } 


    cout << (k - curi) / sumi + 1 << '\n';

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