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
    ll n;
    cin >> n;
    vector<char> a(n), b(n);
    vector<int> c(n), d(n);
    vector<int> s, t;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i] >> b[i] >> d[i];
        if (a[i] == '+' && b[i] == 'x') s.push_back(i), t.push_back(1);
        if (a[i] == 'x' && b[i] == '+') s.push_back(i), t.push_back(0);
        if (a[i] == 'x' && b[i] == 'x') {
            if (c[i] != d[i]) {
                s.push_back(i);
                t.push_back((c[i] < d[i]));
            }
        }
    }

    bool f;
    ll cur_l = 1, cur_r = 1, inc = 0, idx;
    inc += a[0] == '+' ? c[0] : c[0] - 1; 
    inc += b[0] == '+' ? d[0] : d[0] - 1; 
    for (int i = 1; i < n; i++) {
        f = 0;
        if (a[i] == b[i]) {
            if (a[i] == 'x' && c[i] != d[i]) {
                f = c[i] < d[i];
            } else {
                idx = upper_bound(s.begin(), s.end(), i) - s.begin();
                if (idx < s.size()) {
                    f = t[idx];
                }
            }
        } else {
            f = (a[i] != 'x');
        }

        if (f) {
            cur_r += inc;
        } else {
            cur_l += inc;
        }

        inc = 0;
        if (a[i] == 'x') {
            inc += cur_l*(c[i]-1);
        } else {
            inc += c[i];
        }
        if (b[i] == 'x') {
            inc += cur_r*(d[i]-1);
        } else {
            inc += d[i];
        }
    }

    cout << cur_l + cur_r + inc << '\n';
    
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