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
    ll n, m, a, b;

    cin >> n >> m;
    map <int, int> degree;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }

    int cnt = 0;
    for (auto &x: degree) {
        if (x.second == 1) cnt++;
    }

    int x = n - cnt - 1;
    int y = cnt / x;

    cout << x  << ' ' << y << '\n';

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