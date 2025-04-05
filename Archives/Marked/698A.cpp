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
    ll n;
    cin >> n;
    vector<int> via(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> via[i];
    }

    vector<vector<int>> dp(n+1, vector<int> (3));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + (via[i] == 1 || via[i] == 3);
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + (via[i] == 2 || via[i] == 3);
    }
    int x = max(dp[n][0], max(dp[n][1], dp[n][2]));

    cout << n-x << '\n';
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