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


void solve() {
    ll n;
    cin >> n;
    vector <int> via;

    ll x = n;
    while (x) {
        via.push_back(x%10); x /= 10;
    }
    int m = via.size();

    ll a, b, mn, tmp;
    mn = via[0]-7;
    mn += mn < 0 ? 10: 0;
    for (int i = 1; mn && i < m; i++) {
        a = via[i]-7;
        a += a < 0 ? 10 : 0;
        b = 7-via[i];
        b += b < 0 ? 10 : 0;

        if (!(a || b)) {
            mn = 0; break;
        }

        tmp = n % int(powl(10, i));
        if ((tmp+1) + (a-1)*powl(10, i) < mn) 
            mn = (tmp+1) + (a-1)*powl(10, i);

        if (b + (tmp < b) < mn)
            mn = b + (tmp < b);
    }

    cout << min(7, mn) << '\n';
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