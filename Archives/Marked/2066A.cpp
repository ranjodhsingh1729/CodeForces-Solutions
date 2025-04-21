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
    ll n, tmp;
    cin >> n;
    vector<int> X(n+1);
    ll idx1, idxn;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (tmp == 1) idx1 = i;
        if (tmp == n) idxn = i;
        X[tmp]++;
    }

    int f = 0;
    for (int i = 1; i <= n; i++) {
        if (X[i] == 0) {
            f = i;break;
        }
    }

    ll q, w;
    if (f) {
        cout << "? " << f << ' ' << tmp << endl;
        cin >> q;

        if (q == 0) {
            cout << "! A" << endl;
        } else {
            cout << "! B" << endl;
        }
    } else {
        cout << "? " << idx1 << ' ' << idxn << endl;
        cin >> q;
        cout << "? " << idxn << ' ' << idx1 << endl;
        cin >> w;

        if (q && q >= n-1 && q == w) {
            cout << "! B" << endl;
        } else {
            cout << "! A" << endl;
        }
    }
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