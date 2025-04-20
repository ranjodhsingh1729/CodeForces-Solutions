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
    ll n, m;
    cin >> n >> m;
    vector<int> A(m);
    for (int i = 0; i < m; i++)
        cin >> A[i];
    sort(all(A));

    vector<ll> B(m+1, 0);
    B[1] = A[0];
    for (int i = 2; i <= m; i++) {
        B[i] = B[i-1] + A[i-1];
    }

    ll ans = 0, idxa, idxb;
    for (int i = 1; i < n; i++) {
        int a = i, b = n-i;
        idxa = lower_bound(A.begin(), A.end(), a) - A.begin();
        idxb = lower_bound(A.begin(), A.end(), b) - A.begin();

        ans += (m-idxa)*(m-idxb) - min(m-idxa, m-idxb);
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