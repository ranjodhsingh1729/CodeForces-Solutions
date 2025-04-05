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
    ll n, k;
    cin >> n >> k;
    ll x = n-k+1;

    if ((x&1)) {
        if (k&1 && (k+1) % 4 == 0) {
            cout << "YES" << '\n';
        } else if (!(k&1) && k % 4 == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    } else {
        if (k&1 && (k-1) % 4 == 0) {
            cout << "YES" << '\n';
        } else if (!(k&1) && k % 4 == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
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