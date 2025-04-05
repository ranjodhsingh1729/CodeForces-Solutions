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
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll c1 = 0, c2 = 0, t1, t3;
    for (int i = 0; i < n; i++) {
        t1 = c1 + arr[i];
        t3 = c2 + arr[i];
        c1 = min(t1, t3);
        c2 = max(abs(t1), abs(t3));
    }

    cout << max(c1, c2) << '\n';
    
}


int main() {
    FIXIO;

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}