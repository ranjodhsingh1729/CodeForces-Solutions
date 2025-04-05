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

ll ans(ll l, ll n, vector<int> &via) {
    if (l <= n) {
        return via[l] ^ via[l-1];
    } else if (l <= 2*n) {
        return via[l/2];
    } else {
        l = l/2;
        if (!(l&1)) {
            return via[n] ^ ans(l, n, via);
        } else {
            return via[n];
        }
    }
}

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<int> via(n+2, 0);
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

    cout << ans(l, n, via) << '\n';
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