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
    int n, tmp = 0;
    cin >> n;

    vector<int> starts(n+1);
    int start = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        cout << "?" << ' ';
        cout << i << ' ';
        cout << n << ' ';
        for (int j = 1; j <= n; j++) {
            cout << j << ' ';
        }
        cout << endl;
        cin >> tmp;
        starts[i] = tmp;
        if (tmp > mx) {
            mx = tmp;
            start = i;
        }
    }

    vector<int> path(mx);
    path[0] = start;
    for (int k = 1; k <= mx-1; k++) {
        for (int i = 1; i <= n; i++) {
            if (starts[i] == mx-k) {
                cout << "? " << start << ' ';
                cout << k+1 << ' ';
                for (int r = 0; r < k; r++) {
                    cout << path[r] << ' ';
                }
                cout << i << ' ';
                cout << endl;
                cin >> tmp;
                if (tmp == k+1) {
                    path[k] = i;
                    break;
                }
            }
        }
    }
    
    cout << '!' << ' ' << mx << ' ';
    for (auto &i: path) {
        cout << i << ' ';
    }
    cout << endl;
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