#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pre(r, l) for (ll i = (r); i >= ll((l)); i--)
#define fro(l, r) for (ll i = (l); i <= ll((r)); i++)

ll ans_val(ll l, ll n, vector<int> &via) {
    if (l <= n) {
        return via[l] ^ via[l-1];
    } else if (l <= 2*n) {
        return via[l/2];
    } else {
        l = l/2;
        if (!(l&1)) {
            return via[n] ^ ans_val(l, n, via);
        } else {
            return via[n];
        }
    }
}

ll ans_sum(ll l, ll n, vector<int> via, vector<int> &vib) {
    if (l <= 2*n-1) {
        return vib[l];
    } else {
        ll div = (l-(2*n-1))/4;
        ll rem = (l-(2*n-1))%4;

        ll ans1 = 2*via[n]*div;
        ll ans2 = (ans_sum(2*div+n, n, via, vib) - vib[n]);
        if (via[n]) {
            ans2 = 2*div - ans2;
        }
        ll ans = ans1 + ans2;

        switch (rem) {
            case 1:
                return vib[2*n-1] + ans + via[n];
            case 2:
                return vib[2*n-1] + ans + 2*via[n];
            case 3:
                return vib[2*n-1] + ans + 2*via[n] + (via[n] ^ ans_val(2*div+n+1, n, via));
            default:
                return vib[2*n-1] + ans;
        }

    }

}


void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<int> via(n+3, 0);
    for (int i = 1; i <= n; i++) {
        cin >> via[i];
    }

    for (int i = 1; i <= n; i++) {
        via[i] ^= via[i-1];
    }

    if (!(n&1)) {
        via[n+1] = via[(n+1)/2];
        via[n+1] ^= via[n+1-1];
        n++;
    }

    if (l == r) {
        cout << ans_val(l, n, via) << '\n';
        return;
    }

    vector<int> vib(2*n+1);
    for (int i = 1; i <= n; i++) {
        vib[i] = vib[i-1] + (via[i] ^ via[i-1]);
    }
    for (int i = n+1; i <= 2*n; i++) {
        vib[i] = vib[i-1] + (via[i/2]);
    }

    cout << ans_sum(r, n, via, vib) - ans_sum(l-1, n, via, vib) << '\n';
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}