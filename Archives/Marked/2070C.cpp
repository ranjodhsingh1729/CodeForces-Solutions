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


bool ppossible(int p, int k, string &x, vi &via) {
    int count = 0, prv = 1;
    for (int i = 0; i < via.size(); i++) {
        if (via[i] > p) {
            if (x[i] == 'R') {
                prv = 1;
            } else {
                if (prv)
                    count++;
                prv = 0;
            }
        }
    }
    return count <= k;
}


void solve() {
    ll n, k;
    cin >> n >> k;

    string x;
    cin >> x;
    
    vi via(n);
    fro(0, n-1) {
        cin >> via[i];
    }

    int l = 0, r = 0, p;
    for (int i = 0; i < n; i++) {
        if (x[i] == 'B')
            r = max(r, via[i]);
    }
    r += 1;

    bool result;
    while (l < r) {
        p = (l+r)/2;
        result = ppossible(p, k, x, via);
        if (result) {
            r = p;
        } else {
            l = p+1;
        }
    }

    cout << l << '\n';
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