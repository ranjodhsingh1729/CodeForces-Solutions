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


vector<bool> get_seive(int x) {
    vector<bool> is_prime(x+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= x; i++) {
        for (int j = 2; i*j <= x; j++) {
            is_prime[i*j] = false;
        }
    }
    return is_prime;
}


bool is_semi(int x, vector<bool> &is_prime, pair<int,int> &factors) {
    for (int i = 2; i <= sqrtl(x); i++) {
        if (x % i == 0 && is_prime[i] && is_prime[x/i]) {
            factors = {i, x/i};
            return true;
        }
    }
    return false;
}


void solve(vector<bool> &is_prime) {
    ll n; cin >> n;
    vector<int> A(n);
    for (auto &i: A) cin >> i;

    map<int, ll> pp, ss;
    ll ans = 0, ppc = 0;
    pair<int, int> factors;
    for (int i = 0; i < n; i++) {
        if (is_prime[A[i]]) {
            ans += ppc - pp[A[i]];
            ppc++, pp[A[i]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (is_semi(A[i], is_prime, factors)) {
            ss[A[i]]++;
            ans += pp[factors.first];
            if (factors.first != factors.second) {
                ans += pp[factors.second];
            }
        }
    }

    for (auto &i: ss) {
        ans += i.second * (i.second + 1) / 2;
    }
    cout << ans << '\n';
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    cin >> t;

    vector<bool> is_prime = get_seive(ll(2e5+5));
    while (t--) {
        solve(is_prime);
    }

    return 0;
}