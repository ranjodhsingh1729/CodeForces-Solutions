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
    vector<ll> A(n);
    for (auto &i: A) cin >> i;

    if (n == 1) {
        cout << (A[0] == 0)+1 << '\n';
        return;
    }

    vector<ll> dp(n);
    dp[0] = A[0] == 0;
    if (A[1] == A[0]) dp[1] = dp[0];
    if (A[1] == 1) dp[1]++;

    for (int i = 2; i < n; i++) {
        if (A[i] == A[i-1]) {
            dp[i] = mod(dp[i] +  dp[i-1], 998244353);
        }
        if (A[i] == A[i-2] + 1) {
            dp[i] = mod(dp[i] + dp[i-2], 998244353);
        }
    }

    cout << mod(dp[n-1] + dp[n-2], 998244353) << '\n';
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