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

void __mul(ll mod, ll M[2][2], ll N[2][2]) {
    ll temp[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ll res = 0;
            for (int k = 0; k < 2; k++) {
                res += M[i][k]*N[k][j];
            }
            temp[i][j] = res;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            N[i][j] = temp[i][j] % mod;
        }
    }
}

ll fib_mod(ll n, ll mod) {
    if (n == 0) return 0; 
    n -= 2; // Saving Two Operations;
    ll ans[2][2] = { 0, 1, 1, 1 };
    ll cur[2][2] = { 0, 1, 1, 1 };
    while (n > 0) {
        if (n & 1)
            __mul(mod, cur, ans);
        __mul(mod, cur, cur);

        n >>= 1;
    }
    return ans[1][1] % mod;
}


void solve() {
    ll n;
    cin >> n;
    cout << fib_mod(n, 1000000007) << endl;
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