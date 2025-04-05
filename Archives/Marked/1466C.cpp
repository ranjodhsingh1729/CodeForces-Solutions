#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void fileio() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

void solve() {
    string x;
    cin >> x;
    int n = x.size();

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    if (n == 2) {
        cout << (x[0] == x[1] ? 1 : 0) << '\n';
        return;
    }

    int p1, p2, tmp = 0, ans = 0;
    p2 = 0;
    p1 = 0;
    for (int i = 1; i < n; i++) {       
        if (x[i] == x[i-1] && !p1) {
            tmp = 1;
        }
        if (i > 1 && x[i] == x[i-2] && !p2) {
            tmp = 1;
        }

        ans += tmp;
        p2 = p1, p1 = tmp, tmp = 0;
    }

    cout << ans << '\n';
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