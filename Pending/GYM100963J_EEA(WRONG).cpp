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

ll gcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

ll ceil_div(ll p, ll q) {
    // ⌈p/q⌉ for q>0
    if (q < 0) p = -p, q = -q;
    return p >= 0 ? (p + q - 1) / q
                  : p / q;
}

void solve() {
    ll n, m, a, k;
    cin >> n >> m >> a >> k;

    ll start_diff = (a + k) - n;
    ll p1 = m, p2 = a;

    ll u, v;
    ll g = gcd(p1, p2, u, v);
    if (start_diff % g != 0) {
        cout << "Impossible\n";
        return;
    }

    ll mult = start_diff / g;
    ll x0 = u * mult;
    ll y0 = -v * mult;

    ll stepX = p2 / g;
    ll stepY = p1 / g;

    ll t1 = ceil_div(-x0, stepX);
    ll t2 = ceil_div(-y0, stepY);
    ll t  = max(t1, t2);
    ll X = x0 + stepX * t;
    ll Y = y0 + stepY * t;
    if (X < 0 || Y < 0) {
        cout << "Impossible\n";
        return;
    }

    cout << (n + m * X) << "\n";
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