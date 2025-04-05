#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void fileio() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

ll n = 0;
ll cnt = 0;
vector <vector <int>> adj(MAXLEN);


void dfs(int x, int y, int c = 0) {
    if (c)
        cnt++;

    for (int i = 0; i < adj[x].size(); i++) {
        if (y == adj[x][i])
            continue;

        dfs(adj[x][i], x,  !c);
    }
}


void solve() {
    cin >> n;

    int a = 0, b = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1, 1);

    cout << cnt*(n-cnt) - (n-1) << '\n';
}


int main() {
    FIXIO;
    //fileio();

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}