#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n, arr[2*MAXLEN];
    cin >> n;
    ll ans, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+n);

    ll m, x, y, idx;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        idx = lower_bound(arr, arr+n, x) - arr;

        if (idx == 0) {
            ans = max(0, y - (sum - arr[0]));
        } else if (idx == n) {
            ans = max(0, y - (sum - arr[n-1]));
            ans += max(0, x - arr[n-1]);
        } else {
            ll a1, a2;
            a1 = max(0, y - (sum - arr[idx]));
            a2 = max(0, y - (sum - arr[idx-1]));
            a2 += max(0, x - arr[idx-1]);
            ans = min(a1, a2);
        }

        cout << ans << '\n';
    }
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