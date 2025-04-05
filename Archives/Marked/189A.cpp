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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll dp[4001];

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
        if (i - a >= 0 && dp[i-a] >= 0)
            dp[i] = max(dp[i], dp[i-a] + 1);
        if (i - b >= 0 && dp[i-b] >= 0)
            dp[i] = max(dp[i], dp[i-b] + 1);
        if (i - c >= 0 && dp[i-c] >= 0)
            dp[i] = max(dp[i], dp[i-c] + 1);
    }

    // for (int i = 0; i <= n; i++)
    //     cout << dp[i] << ' ';
    // cout << '\n';

    cout << dp[n] << '\n';
}


int main() {
    FIXIO;
    //fileio();

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}