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

bool checkk(ll n, ll k) {
    while (n > 0) {
        if ((n-1) % k == 0) {
            n = (n-1) / k;
        } else {
            return false;
        }
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;

    ll l = ceil(-1 + sqrtl(4*n-3)) / 2;
    // cout << l << '\n';

    int f = 0;
    for (int i = l; i > 1; i--) {
        if (checkk(n, i)) {
            f = 1;
            break;
        }
    }

    if (f) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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