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

const ll MOD = 998244353;

void solve() {
    ll n;
    cin >> n;
    vector <int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll ans = 0, nof1 = 0;
    vector<ll> dp(n+1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        switch (A[i-1])
        {
        case 1:
            nof1++;
            break;
        case 2:
            dp[i] = (2*dp[i-1] + nof1) % MOD;
            break;
        case 3:
            ans = (ans + dp[i-1]) % MOD;
            break;
        default:
            break;
        }
    }

    cout << ans << '\n';
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