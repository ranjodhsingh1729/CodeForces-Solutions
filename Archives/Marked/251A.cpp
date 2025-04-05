#include <math.h>
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
    ll n, d, arr[MAXLEN];
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n < 3) {
        cout << 0 << '\n';
        return;
    }

    ll idx;
    ll cnt = 0;
    for (int i = 0; i < n-2; i++) {
        idx = lower_bound(arr, arr+n, arr[i]+d) - arr;

        if (idx < n) {
            if (arr[i] + d != arr[idx]) {
                idx -= 1;
            }
        } else {
            idx = n-1;
        }
        
        if (idx-i > 1) {
            cnt += (idx-i)*(idx-i-1)/2; 
        }

    }

    cout << cnt << '\n';


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