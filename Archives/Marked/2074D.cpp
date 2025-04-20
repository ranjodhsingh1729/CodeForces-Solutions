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


void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> X(n), R(n);
    for (auto &i: X) cin >> i;
    for (auto &i: R) cin >> i;

    map<ll, ll> xtoa;
    ll ai, xi, ri, pos1, pos2;
    for (ll j = 0; j < n; j++) {
        xi = X[j], ri = R[j];
        for (ll i = 0; i < ri; i++) {
            pos1 = xi-ri+i, pos2 = xi+ri-i;
            ai = (ll)floorl(sqrtl(ri*ri - (xi-pos1)*(xi-pos1)));
            xtoa[pos1] = max(xtoa[pos1], ai), xtoa[pos2] = max(xtoa[pos2], ai);
        }
        xtoa[xi] = max(xtoa[xi], ri);
    }

    ll cnt = 0;
    for (auto &i: xtoa) {
        cnt += 2*i.second+1;
    }

    cout << cnt << '\n';
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