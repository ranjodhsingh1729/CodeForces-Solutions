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
    ll l, r;
    cin >> l >> r;

    int x = l;
    for (int i = 1; i < 3 && l+i <= r; i++) {
        if ((l+i)/3 == x/3 && (l+i)%3 >= x%3) {
            x = l+i;
        }
    }

    ll ans = floorl(log2l(x)/log2l(3) + 1);

    ll cnt = 0;
    for (int i = 1; i <= floorl(log2l(l)/log2l(3) + 1); i++) {
        cnt += (min(l, powl(3, i)) - powl(3, i-1))*(i);
    }
    
    cnt = -cnt;
    for (int i = 1; i <= floorl(log2l(r+1)/log2l(3) + 1); i++) {
        cnt += (min(r+1, powl(3, i)) - powl(3, i-1))*(i);
    }

    cout << ans+cnt << '\n';
   
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