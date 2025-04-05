#include <bits/stdc++.h>

using namespace std;
typedef int64_t ll;
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


ll ans_sum(ll l, ll n, vector<int> &vib) {
    if (l <= 2*n-1) {
        return vib[l];
    } else {
        ll p = 1&vib[n];
        ll div = (l-(2*n-1))/4;
        ll rem = (l-(2*n-1))%4;

        ll tmp = ans_sum(2*div+n, n, vib);
        ll ans = vib[2*n-1] + 2*p*div + (p ? 2*div-(tmp-vib[n]) : (tmp-vib[n]));

        if (rem >= 1) {
            ans += p;
        }
        if (rem >= 2) {
            ans += p;
        }
        if (rem == 3) {
            ans += (p ^ (ans_sum(2*div+n+1, n, vib) - tmp));
        }

        return ans;
    }

}


void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<int> via(2*n+3, 0);
    for (int i = 1; i <= n; i++) {
        cin >> via[i];
    }

    for (int i = 1; i <= n; i++) {
        via[i] += via[i-1];
    }

    if (!(n&1)) {
        via[n+1] = 1&via[(n+1)/2];
        via[n+1] += via[n];
        n++;
    }

    for (int i = n+1; i <= 2*n; i++) {
        via[i] = via[i-1] + (1&via[i/2]);
    }

    cout << ans_sum(r, n, via) - ans_sum(l-1, n, via) << '\n';
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