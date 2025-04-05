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
    vector <pair<int,int>> vpia(n);
    for (int i = 0; i < n; i++) {
        cin >> vpia[i].first >> vpia[i].second;
    }

    if (n <= 2) {
        cout << min(n, 2) << '\n'; return;
    }

    ll count = 2, leftocc;
    leftocc = vpia[0].first;
    for (int i = 1; i < n-1; i++) {
        if (leftocc < vpia[i].first-vpia[i].second) {
            count++;
            leftocc = vpia[i].first;
        } else if (vpia[i+1].first > vpia[i].first+vpia[i].second) {
            count++;
            leftocc = vpia[i].first+vpia[i].second;
        } else {
            leftocc = vpia[i].first;
        }
    }

    cout << count << '\n'; return;
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}