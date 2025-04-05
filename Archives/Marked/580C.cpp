#include <bits/stdc++.h>
 
#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll MOD = 1e9+7;
const int MAXN = 1e6+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;
 
 
void leafcount(int x, int &ans, vector<bool> &visited, vector<vector<int>> &adj) {
    visited[x] = true;

    if (x != 1 && adj[x].size() == 1) {
        ans++;
    } else {
        for (auto &i: adj[x]) {
            if (!visited[i])
                leafcount(i, ans, visited, adj);
        }
    }
}
 
 
void dfs(int x, int &a, int &cats, int &ans, int m, vector<bool> &visited, vector<bool> &via, vector<vector<int>> &adj) {
    visited[x] = true;

    int pa = a;
    int pcats = cats;

    if (via[x]) {
        if (a) cats++;
        else cats = a = 1;
    } else {
        if (a) cats = a = 0;
    }
 
    if (cats > m) {
        leafcount(x, ans, visited, adj);
    } else {
        for (auto &i: adj[x]) {
            if (!visited[i])
                dfs(i, a, cats, ans, m, visited, via, adj);
        }
    }
 
    if (via[x]) {
        if (a) cats--;
        else cats = a = 0;
    } else {
        if (pa) {
            a = pa;
            cats = pcats;
        }  
    }
}
 
 
void solve() {
    int a, b;
    int n, m;
    cin >> n >> m;
    vector <bool> via(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        via[i] = a;
    }
 
    vector<vector<int>> adj(n+1);
    for (int i = 1; i <= n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    int cats, ans;
    cats = ans = a = b= 0;
    vector <bool> visited(n+1);
    dfs(1, a, cats, ans, m, visited, via, adj);
 
    int leaves = 0;
    for (int i = 2; i <= n; i++) {
        if (adj[i].size() == 1) leaves++;
    }

    cout << leaves - ans << '\n';
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