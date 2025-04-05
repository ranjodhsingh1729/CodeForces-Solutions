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
    int n, tmp;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 2; i <= n; i++) {
        cin >> tmp;
        adj[i].push_back(tmp);
        adj[tmp].push_back(i);
    }

    queue<int> Q;
    vector<ll> moves(n+1, 0);
    vector<bool> visited(n+1, false);

    moves[1] = 1;
    visited[1] = true;
    for (auto &i: adj[1]) {
        Q.push(i);
        moves[i] = 1;
        visited[i] = true;
    }

    while (!Q.empty()) {
        int cnt = Q.size();

        ll sum = 0, tmp;
        for (int i = 0; i < cnt; i++) {
            tmp = Q.front();
            Q.pop();
            sum = mod(sum + moves[tmp], 998244353);
            Q.push(tmp);
        }

        for (int i = 0; i < cnt; i++) {
            int cur = Q.front(); Q.pop();
            for (auto &j: adj[cur]) {
                if (visited[j]) continue;

                Q.push(j);
                visited[j] = true;
                moves[j] = mod(moves[j] + (sum-moves[cur]), 998244353);
            }
        }
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = mod(sum + moves[i], 998244353);
    }
    cout << sum << '\n';
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