#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n, k, tmp;
    cin >> n >> k;
    multiset<int> mset;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        mset.insert(-tmp);
    }

    int c = 1, f = 0;
    while (!mset.empty()) {
        auto itr = mset.lower_bound(f-k);
        if (itr != mset.end()) {
            f += -(*itr);
            mset.erase(itr);
        } else {
            f = 0, c++;
        }
    }

    cout << c << '\n';
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