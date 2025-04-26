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


struct DSU {
    int n;
    vector<int> P;

    DSU(int n) {
        this->n = n;
        this->P.assign(n, 0);
        for (int i = 0; i < n; i++) P[i] = i;
    }

    void make_set(int v) {
        P[v] = v;
    }
    
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            P[b] = a;
        }
    }

    int find_set(int a) {
        if (P[a] != a)
            return (P[a] = find_set(P[a]));
        return a;
    }
};


void solve() {
    ll n, m1, m2;
    cin >> n >> m1 >> m2;

    int a, b;
    set<pair<int,int>> f, g;
    vector<vector<int>> F(n+1), G(n+1);
    for (int i = 0; i < m1; i++) {
        cin >> a >> b;
        f.insert({min(a, b), max(a, b)});
    }
    for (int i = 0; i < m2; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        g.insert({min(a, b), max(a, b)});
    }

    vector<int> tmp;
    vector<bool> vis(n+1, false);
    function<void(int, bool)> dfs = [&](int x, bool f) -> void {
        vis[x] = true;
        tmp.push_back(x);
        for (auto &i: (f ? F : G)[x])
            if (!vis[i])
                dfs(i, f);
    };

    int id;
    DSU FCC(n+1), GCC(n+1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
            id = 0;
            for (auto &k: tmp) {
                if (id) {
                    GCC.union_set(k, id);
                } else {
                    id = k;
                    GCC.make_set(k);
                }
            }
            tmp.clear();
        }
    }
    ll count = 0;
    for (auto i = f.begin(); i != f.end(); ) {
        if (GCC.find_set(i->first) != GCC.find_set(i->second)) {
            count++;
            f.erase(*(i++));
        } else {
            i++;
        }
    }
    
    for (auto &i: f) {
        F[i.first].push_back(i.second);
        F[i.second].push_back(i.first);
    }
    fill(vis.begin(), vis.end(), false);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 1);
            id = 0;
            for (auto &k: tmp) {
                if (id) {
                    FCC.union_set(k, id);
                } else {
                    id = k;
                    FCC.make_set(k);
                }
            }
            tmp.clear();
        }
    }

        
    for (auto i = g.begin(); i != g.end(); i++) {
        if (FCC.find_set(i->first) != FCC.find_set(i->second)) {
            count++;
            FCC.union_set(i->first, i->second);
        }
    }

    // set<int> gcc, fcc;
    // for (int i = 1; i <= n; i++) {
    //     gcc.insert(GCC.find_set(i));
    //     fcc.insert(FCC.find_set(i));
    // }
    // count += abs((int)(gcc.size()-fcc.size()));

    cout << count << '\n';
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