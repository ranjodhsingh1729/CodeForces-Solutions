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
    ll n, a, b;
    cin >> n >> a >> b;
    ll x, y;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> bfs;
    bfs.push_back(b);
    vector<bool> vis(n+1, false);
    vis[b] = true;
    for (int i = 0; i < bfs.size(); i++) {
        for (int j : adj[bfs[i]]) {
            if (!vis[j]) {
                vis[j] = true;
                bfs.push_back(j);
            }
        }
    }

    for (int i = bfs.size(); i > 0; i--) {
        cout << bfs[i-1] << ' ';
    }
    cout << '\n';
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