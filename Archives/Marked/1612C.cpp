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
    ll k, x;
    cin >> k >> x;

    ll sum = k*(k+1)/2;
    
    ll tmp;
    ll l = 1, r = 2*k-1, p;
    while (l < r) {
        p = (l+r)/2;
        
        if (p > k) {
            tmp = sum + ( k*(k-1)/2 - (2*k-p)*(2*k-p-1)/2 );
        } else {
            tmp = p*(p+1)/2;
        }

        if (tmp >= x) {
            r = p;
        } else {
            l = p+1;
        }
    }

    cout << l << '\n';
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