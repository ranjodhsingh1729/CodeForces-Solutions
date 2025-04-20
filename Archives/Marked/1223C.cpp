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


bool check(ll noft, ll x, ll y, ll a, ll b, ll target, vector<ll> &A) {
    ll ans = 0;
    ll p = x >= y ? x : y;
    ll r = x < y ? x : y;
    ll g = x >= y ? a : b;
    ll t = x < y ? a : b;

    ll e = noft/lcm(g,t);
    ll q = noft/g - e;
    ll w = noft/t - e;

    ll k = 0;
    for (int i = 0; i < e; i++) {
        ans += (p+r) * A[k++];
    }
    for (int i = 0; i < q; i++) {
        ans += p * A[k++];
    }
    for (int i = 0; i < w; i++) {
        ans += r * A[k++];
    }
    
    return ans >= target;
}


void solve() {
    ll n;
    cin >> n;
    vector<ll> A(n);
    for (auto &i: A) cin >> i, i /= 100;
    sort(A.begin(), A.end(), greater<ll>());

    ll x, a, y, b;
    cin >> x >> a >> y >> b;
    ll k;
    cin >> k;

    if (!check(n, x, y, a, b, k, A)) {
        cout << -1 << '\n';
        return;
    }

    ll l = 0, r = n, p;
    while (l <= r) {
        p = l + (r - l) / 2;
        if (check(p, x, y, a, b, k, A)) {
            r = p-1;
        } else {
            l = p+1;
        }
    }

    cout << l << '\n';
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