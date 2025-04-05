#include <bits/stdc++.h>

#define MAXLEN 100000
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

int dfs(int x, int arr[], vector<bool> &visited, vector<vector<int>> &adj) {
    visited[x] = true;
    int cost = arr[x-1], temp;
    for (auto &i: adj[x]) {
        temp = arr[i-1];
        if (!visited[i]) {
            temp = dfs(i, arr, visited, adj);
        }
        cost = min(cost, temp);   
    }
    return cost; 
}

void solve() {
    int n, m, arr[2*MAXLEN];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int u, v;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll sum = 0;
    vector<bool> visited(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            sum += dfs(i, arr, visited, adj);
        }
    }
    cout << sum << '\n';
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