#include <algorithm>
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

    vector<int> N(n);
    for (int i = 0; i < n; i++) {
        cout << '?' << ' ';
        cout << i+1 << ' ';
        cout << n << ' ';
        for (int j = 0; j < n; j++) {
            cout << j+1 << ' ';
        }
        cout << endl;

        cin >> N[i];
    }

    int maxIdx = max_element(N.begin(), N.end()) - N.begin();
    int maxVal = N[maxIdx];

    vector<int> path;
    path.push_back(maxIdx+1);
    for (int i = maxVal-1; i >= 1; i--) {
        int x = -1;
        for (int j = n-1; j >= 0; j--) {
            if (N[j] != i) continue;

            cout << '?' << ' ';
            cout << path[path.size()-1] << ' ';
            cout << 2 << ' ';
            cout << path[path.size()-1] << ' ';
            cout << j+1 << ' ';
            cout << endl;

            cin >> x;
            if (x == 2) {
                path.push_back(j+1);
                break;
            }
        }
        assert(x == 2);
    }

    cout << '!' << ' ';
    cout << path.size() << ' ';
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