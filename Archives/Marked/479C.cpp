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
    vector<pair<int,int>> via(n);
    for (int i = 0; i < n; i++) {
        cin >> via[i].first >> via[i].second;
    }
    sort(via.begin(), via.end(),
        [](pair<int,int> &a, pair<int,int> &b){
            return a.first==b.first?a.second<b.second:a.first<b.first;
        }
    );


    int ans = min(via[0].first, via[0].second);
    for (int i = 1; i < n; i++) {
        if (via[i].second < ans) {
            ans = via[i].first;
        } else {
            ans = via[i].second;
        }
    }

    cout << ans << '\n';
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