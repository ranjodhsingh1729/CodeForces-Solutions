#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n, temp;
    cin >> n;
    multiset<int> mset;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        mset.insert(temp);
    }

    ll hcf, mx, mxi;
    hcf = *(mset.rbegin());
    cout << hcf << ' ';
    mset.erase(mset.lower_bound(hcf));
    while (!mset.empty()) {
        mx = 0;
        for (auto &x: mset) {
            if (mx < gcd(x, hcf)) {
                mx = gcd(x, hcf);
                mxi = x;
            }
        }
        hcf = mx;
        cout << mxi << ' ';
        mset.erase(mset.lower_bound(mxi));
    }

    cout << '\n';
}


int main() {
    FIXIO;

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}