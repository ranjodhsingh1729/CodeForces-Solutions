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
    vector<ll> A(n+1);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<int> update(n);
    ll sum = 0;
    for (int i = 2; i <= n; i+=2) {
        update[i] = max((A[i-1] + (i+1<=n?A[i+1]:0)) - A[i], 0);
        sum += update[i];
    }

    ll cost = 0, mx, f;
    for (int i = 2; i <= n; i+=2) {
        mx = 0, f = -1;
        if (i-2 >= 1 && update[i-2] >= mx) {
            f = 1;
        }
        if (i+2 <= n && update[i+2] >= mx) {
            f = 2;
        }

        if (f == 1) {
            cost += update[i];
            update[i-2] -= min(update[i-2], update[i]);
            update[i] = 0;
        }
        if (f == 2) {
            cost += update[i];
            update[i+2] -= min(update[i+2], update[i]);
            update[i] = 0;
        }
    }


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