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
    int n;
    cin >> n;
    int a, b;
    vector<set<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int mx1, mx2;
    mx1 = mx2 = 0;
    for (int i = 1; i <= n; i++) {
        if (mx1 < adj[i].size()) {
            mx2 = mx1;
            mx1 = adj[i].size();
        } else {
            if (mx2 < adj[i].size()) {
                mx2 = adj[i].size();
            }
        }
    }

    vector<int> maxes;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == mx1) {
            maxes.push_back(i);
        }
    }

    int g = 0;
    if (maxes.size() == 1) {
        g = 1;
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() == mx2) {
                maxes.push_back(i);
            }
        }
    }

    int i, j, f = 1;
    for (j = 1; j < maxes.size(); j++) {
        if (adj[maxes[0]].find(maxes[j]) == adj[maxes[0]].end()) {
            f = 0; break;
        }
    }

    // ONLY GOD AND ME KNOWS :)
    int ans = 0;
    if (g) {
        ans = !f?(1+(mx1-1)+(mx2-1)):(1+(mx1-1)+(mx2-2));
    } else {
        ans = (maxes.size()>2)?(1+(mx1-1)+(mx1-1)):(!f?(1+(mx1-1)+(mx1-1)):(1+(mx1-1)+(mx1-2)));
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