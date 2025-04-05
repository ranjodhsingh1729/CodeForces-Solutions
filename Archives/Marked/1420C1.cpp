#include <bits/stdc++.h>

#define MAXLEN 100001
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
    ll n, q, arr[3*MAXLEN];

    cin >> n >> q;
    for (int i = 0; i    < n; i++) {
        cin >> arr[i];
    }

    ll dp1[MAXLEN];
    ll dp2[MAXLEN];

    dp1[0] = arr[0], dp2[0] = 0;
    for (int i = 1; i < n; i++) {
        dp1[i] = max(dp1[i-1], dp2[i-1]+arr[i]);
        dp2[i] = max(dp2[i-1], dp1[i-1]-arr[i]);
    }

    cout << max(dp1[n-1], dp2[n-1]) << '\n';
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