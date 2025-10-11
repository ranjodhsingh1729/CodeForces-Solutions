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
    string x, y;
    cin >> x >> y;

    ll p = x.size();
    ll q = y.size();
    ll f = lcm(p, q);
    ll g = gcd(p, q);

    ll ans = f;
    map<pair<int,int>, int> count;
    for (ll i = 0; i < p; i++) {
        count[make_pair(i % g, x[i])]++;
    }
    for (ll i = 0; i < q; i++) {
        ans -= count[make_pair(i % g, y[i])];
    }

    cout << p * n / f * ans << endl;
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}