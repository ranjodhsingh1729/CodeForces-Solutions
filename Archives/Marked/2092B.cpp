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
    string x, y;
    cin >> x >> y;

    ll c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            c1 += x[i] == '0';
            c2 += y[i] == '0';
        } else {
            c1 += y[i] == '0';
            c2 += x[i] == '0';
        }
    }

    bool f;
    if (n % 2 == 0) {
        f = (c1 >= n/2 && c2 >= n/2);
    } else {
        f = (c1 >= n/2+1 && c2 >= n/2);
    }

    cout << (f ? "YES" : "NO") << '\n';
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