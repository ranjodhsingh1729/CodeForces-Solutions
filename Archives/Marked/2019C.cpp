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
    ll n, k, arr[2*MAXLEN];
    cin >> n >> k;

    ll mx = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
        sum += arr[i];
    }

    ll others = sum - mx;

    ll maxothers = others + k;
    ll deck_size = maxothers / mx;
    ll remaining = maxothers % mx;
    
    remaining %= deck_size+1;

    bool f = 0;
    if (remaining - k <= 0) {
        f = 1;
    }


    if (f) {
        cout << (deck_size + 1 <= n ? deck_size + 1 : n ) << '\n';
    } else {
        cout << 1 << '\n';
    }
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