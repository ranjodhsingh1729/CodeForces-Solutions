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
    vector<int> A(n), B(n);
    for (auto &i: A) cin >> i;
    for (auto &i: B) cin >> i;

    int c = 0, f = -1;
    vector<int> C(n+1);
    for (int i = 0; i < n; i++) {
        C[A[i]] = i;
        if (A[i] == B[i]) f = i, c++;
    }
    if (c != (n&1)) {
        cout << -1 << '\n';
        return;
    }

    vector<pair<int,int>> ans;
    if (c && f != n/2) {
        ans.push_back({f, n/2});
        swap(A[f], A[n/2]);
        swap(B[f], B[n/2]);
        C[A[f]] = f, C[A[n/2]] = n/2;
    }


    bool z = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == B[i]) continue;

        if (B[C[B[i]]] != A[i]) {
            z = 1; break;
        }
    }

    if (z) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (C[B[i]] != n-i-1) {
            ans.push_back({C[B[i]], n-i-1});
            swap(A[C[B[i]]], A[n-i-1]);
            swap(B[C[B[i]]], B[n-i-1]);
            C[A[C[B[i]]]] = C[B[i]], C[A[n-i-1]] = n-i-1;
        }
    }

    cout << ans.size() << '\n';
    for (auto &i: ans)
        cout << i.first+1 << ' ' << i.second+1 << '\n';

    // for (auto &i: A) cout << i << ' ';
    // cout << '\n';

    // for (auto &i: B) cout << i << ' ';
    // cout << '\n';
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