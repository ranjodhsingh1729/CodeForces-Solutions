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
    ll x, n, m;
    cin >> x >> n >> m;

    ll maxops = x ? ceil(log2(x)): 0;

    ll mx = x;
    for (int i = 0; i < n && i <= maxops; i++) {
        mx = (mx>>1);
    }
    for (int i = 0; i < m && i <= maxops; i++) {
        mx = (mx>>1)+(mx& 1);
    }

    ll mn = x;
    for (int i = 0; i < m && i <= maxops; i++) {
        mn = (mn>>1)+(mn&1);
    }
    for (int i = 0; i < n && i <= maxops; i++) {
        mn = (mn>>1);
    }
    
    cout << mn << ' ' << mx << '\n';
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
};