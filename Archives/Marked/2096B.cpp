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
    ll n, k;
    cin >> n >> k;
    vector<int> L(n);
    vector<int> R(n);
    for (auto &i: L) cin >> i;
    for (auto &i: R) cin >> i;

    int mn, mx;
    for (int i = 0; i < n; i++) {
        mx = max(L[i], R[i]);
        mn = min(L[i], R[i]);
        L[i] = mx, R[i] = mn;
    }
    sort(R.begin(), R.end());

    ll ans = 0;
    ans = accumulate(L.begin(), L.end(), ans);
    ans = accumulate(R.begin()+(n-k+1), R.end(), ans);
    cout << ans+1 << '\n';
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