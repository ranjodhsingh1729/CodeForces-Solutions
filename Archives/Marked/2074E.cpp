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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> udist(0, 2);


void solve() {

    ll n;
    cin >> n;

    assert(n != -1);

    vector<int> q(3);
    q[0] = 1, q[1] = 2, q[2] = 3;
    ll x = -1;
    while (1) {
        cout << "? " << q[0] << ' ' << q[1] << ' ' << q[2] << endl;

        cin >> x;
        if (x == 0) {
            cout << "! " << q[0] << ' ' << q[1] << ' ' << q[2] << endl;
            break;
        }

        q[udist(rng)] = x;
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