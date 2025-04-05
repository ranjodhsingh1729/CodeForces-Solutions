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
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll l = 0, r = 0, sum = 0, best = 0;
    while (r < n) {
        if (sum + arr[r] <= k) {
            sum += arr[r++];
        } else {
            sum -= arr[l++]; 
        }
        best = max(best, r-l);
    }

    cout << r-l << '\n';
}


int main() {
    // FIXIO;
    // fileio();

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}