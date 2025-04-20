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
    vll A(n), B(n);
    vector<vector<ll>> h(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> h[i][j];
    for (ll i = 0; i < n; i++) cin >> A[i];
    for (ll j = 0; j < n; j++) cin >> B[j];

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<array<bool,3>> rowrestrict(n-1);
    for (ll i = 0; i < n-1; i++) {
        rowrestrict[i] = {false, false, false};
        for (ll j = 0; j < n; j++) {
            ll D = h[i][j] - h[i+1][j];
            if (-1 <= D && D <= 1) rowrestrict[i][D+1] = true;
        }
    }

    array<ll,2> dp = {0, A[0]}, dp_2;
    for (ll i = 0; i < n-1; i++) {
        dp_2 = {INF, INF};
        for (int v = 0; v < 2; v++) if (dp[v] < INF) {
            for (int d = -1; d <= 1; d++) {
                if (rowrestrict[i][d+1]) continue;
                int nv = v + d;
                if (nv < 0 || nv > 1) continue;
                ll c = dp[v] + (nv ? A[i+1] : 0);
                dp_2[nv] = min(dp_2[nv], c);
            }
        }
        dp = dp_2;
    }

    ll best_row = min(dp[0], dp[1]);
    if (best_row >= INF) {
        cout << -1 << '\n';
        return;
    }

    vector<array<bool,3>> colrestrict(n-1);
    for (ll j = 0; j < n-1; j++) {
        colrestrict[j] = {false, false, false};
        for (ll i = 0; i < n; i++) {
            ll D = h[i][j] - h[i][j+1];
            if (-1 <= D && D <= 1) colrestrict[j][D+1] = true;
        }
    }

    array<ll,2> dp_col = {0, B[0]};
    for (ll j = 0; j < n-1; j++) {
        dp_2 = {INF, INF};
        for (int v = 0; v < 2; v++) if (dp_col[v] < INF) {
            for (int d = -1; d <= 1; d++) {
                if (colrestrict[j][d+1]) continue;
                int nv = v + d;
                if (nv < 0 || nv > 1) continue;
                ll c = dp_col[v] + (nv ? B[j+1] : 0);
                dp_2[nv] = min(dp_2[nv], c);
            }
        }
        dp_col = dp_2;
    }

    ll best_col = min(dp_col[0], dp_col[1]);
    if (best_col >= INF) {
        cout << -1 << '\n';
        return;
    }

    cout << best_row + best_col << '\n';
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
