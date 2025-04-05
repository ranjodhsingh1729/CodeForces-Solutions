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

void remove(int x, int n, vector<set<int>> &via) {
    for (int i = 1; i <= n; i++) {
        if (i == x) via[i].clear();
        else via[i].erase(x);
    }
}

void dfs(int x, vector<bool> &visited, vector<set<int>> &via) {
    if (!visited[x]) {
        visited[x] = true;
        for (auto &i : via[x]) {
            dfs(i, visited, via);
        }
    }
}

void solve() {
    ll n;
    int a, b;
    cin >> n;
    vector <set<int>> via(n+1);
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        via[a].insert(b);
        via[b].insert(a);
    }




    int c = 0;
    vector<bool> visited(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            c++;
            dfs(i, visited, via);
        }
    }

    cout << c-2 << '\n';
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