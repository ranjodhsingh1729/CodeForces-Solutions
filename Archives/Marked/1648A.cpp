#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<ll, 3> triple;
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
    vector<vector<int>> A(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    map<int, vector<int>> X;
    map<int, vector<int>> Y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            X[A[i][j]].push_back(i);
            Y[A[i][j]].push_back(j);
        }
    }

    ll sum = 0, pref;
    for (auto &a: X) {
        sort(a.second.begin(), a.second.end());
        pref = a.second[0];
        for (int i = 1; i < a.second.size(); i++) {
            sum += (ll)i*a.second[i] - pref;
            pref += a.second[i];
        }
    }

    for (auto &a: Y) {
        sort(a.second.begin(), a.second.end());
        pref = a.second[0];
        for (int i = 1; i < a.second.size(); i++) {
            sum += (ll)i*a.second[i] - pref;
            pref += a.second[i];
        }
    }

    cout << sum << '\n';
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