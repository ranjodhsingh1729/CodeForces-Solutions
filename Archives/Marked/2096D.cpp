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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> A(n);
    for (auto &i: A) cin >> i.first >> i.second;

    map <ll, ll> Xi, Di;
    for (auto &i: A) Xi[i.first]++, Di[i.first+i.second]++;

    ll s = LONG_LONG_MAX;
    for (auto &i: Xi) {
        if (i.second&1) {
            s = i.first; break;
        }
    }
    assert(s != LONG_LONG_MAX);

    ll d = LONG_LONG_MAX;
    for (auto &i: Di) {
        if (i.second&1) {
            d = i.first; break;
        }
    }
    assert(d != LONG_LONG_MAX);


    cout << s << ' ' << d-s << '\n';
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