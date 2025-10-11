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
    ll n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (auto &i: A) cin >> i;

    vector<int> xnors(n);
    // Adjacent xnors
    for (int i = 0; i < n-1; i++)
        xnors[i+1] = !(A[i] ^ A[i+1]);

    // Prefix Sum xnors
    for (int i = 1; i < n; i++)
        xnors[i] += xnors[i-1];

    // xnors array
    // 0, xnor01, xnor01 + xnor12, xnor01 + xnor12 + xnor23, ...
    // lets say you have an l = 1 and an r = 3
    // so no of same adjacent pairs will be xnors[r] - xnors[l-1]

    // Prefix Sum A
    for (int i = 1; i < n; i++)
        A[i] += A[i-1];

    int l, r;
    while (q--) {
        cin >> l >> r;
        r--, l--;

        int count = r - l + 1;
        int count1s = A[r] - (l-1 >= 0 ? A[l-1] : 0);
        int count0s = count - count1s;

        if ((count1s % 3 != 0) || (count0s % 3 != 0)) {
            cout << -1 << '\n';
            continue;
        }

        // If Control Flow reaches here
        // then count is definitly divisible by 3

        cout << (count / 3 + !(bool)(xnors[r] - xnors[l])) << '\n';
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