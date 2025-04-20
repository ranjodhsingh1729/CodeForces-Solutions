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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ll sum = accumulate(A.begin(), A.end(), 0LL);

    ll q = x / sum;
    ll rem = x % sum;

    ll c = 0;
    for (int i = n-1; i >= 0; i--) {
        if (c >= rem) {
            c = n - (i + 1);
            break;
        }
        c += A[i];
        if (c >= rem) {
            c = n - i;
            break;
        }
    }

    ll req = (q*n) + c;

    ll ans;
    if (req > k*n) {
        ans = 0;
    } else {
        ans = (k*n) - req + 1;        
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