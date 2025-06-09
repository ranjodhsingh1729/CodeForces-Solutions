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
    ll n, m, T;
    cin >> n >> m >> T;
    vector<int> A(n+1);
    vector<int> B(m+1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }

    ll mx = 0, mn, st;
    for (int i = 1; i <= m; i++) {
        mn = A[B[i]];
        st = mn;
        if (B[i]+1 <= n) {
            mn = min(mn, A[B[i]+1]);
        }
        if (B[i-1]-1 >= 1) {
            mn = min(mn, A[B[i]-1]);
        }

        if (st <= T) {
            mx = max(mx, 1+(T-st)/mn);
        }
    }

    cout << mx << endl;
}


int main() {
    FIXIO;

    ll t;
    t = 1;

    while (t--) {
        solve();
    }

    return 0;
}