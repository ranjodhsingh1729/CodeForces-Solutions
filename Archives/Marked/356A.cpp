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
    vector<triple> A(m);
    for(auto &i: A) cin >> i[0] >> i[1] >> i[2];

    set<int> ingame; vector<int> ans(n);
    for (int i = 1; i <= n; i++) ingame.insert(i);
    for (auto &i: A) {
        auto l = ingame.lower_bound(i[0]);
        auto r = ingame.upper_bound(i[1]);
        for (auto j = l; j != r;) {
            if (*j != i[2]) {
                ans[*j-1] = i[2];
                ingame.erase(*(j++));
            } else {
                j++;
            }
        }
    }

    for (auto &i: ans) {
        cout << i << ' ';
    }
    cout << '\n';
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