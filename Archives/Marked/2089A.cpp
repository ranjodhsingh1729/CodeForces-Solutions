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

bool is_prime(ll x) {
    for (ll i = 2; i <= sqrtl(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


void solve() {
    ll n;
    cin >> n;

    ll p = -1;
    for (ll i = ceil(n/3.0); i <= floor(2.0*n/3.0); i++) {
        if (is_prime(i)) {
            p = i; break;
        }
    }
    assert(p != -1); // bertland's postulate

    ll i;
    cout << p << ' ';
    for (i = 1; p - i > 0 && p + i <= n; i++) {
        cout << p - i << ' ' << p + i << ' ';
    }
    for (ll j = 1; j <= n; j++) {
        if (j <= p-i || j >= p+i) {
            cout << j << ' ';
        }
    }
    cout << '\n';

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