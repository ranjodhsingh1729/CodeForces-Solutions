#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((a) - (b)*(floor((long double) a / b)))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
typedef array<int,3> triple;
const ll MOD = 998244353;
const ll INF = 0x3f3f3f3f3f3f3f3f;

void fileio() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

void solve() {
    ll n;
    cin >> n;
    map <int, int> portals;
    vector <pair <int, int>> points;

    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        portals[a] = b;
        points.push_back(make_pair(a, c));
        points.push_back(make_pair(b, -1));
    }
    sort(points.begin(), points.end());

    map <int, ll> dp1;
    map <int, ll> dp2;

    pair <int, int> prev = make_pair(0, -1);
    for (int i = 0; i < 2*n; i++) {
        b = prev.first;
        c = points[i].first;
        if (prev.second == -1) {
            dp1[c] = mod((dp1[b] + c-b), MOD);
        } else {
            dp1[c] = mod((dp1[b] + dp1[b]-dp1[portals[b]] + c-b), MOD);
        }
        prev = points[i];
    }

    // for (auto x: dp1) {
    //     cout << x.first << ':' << x.second << '\n';
    // }

    prev = make_pair(0, -1);
    for (int i = 0; i < 2*n; i++) {
        b = prev.first;
        c = points[i].first;
        if (prev.second == 0 || prev.second == -1) {
            dp2[c] = mod((dp2[b] + c-b), MOD);
        } else {
            dp2[c] = mod((dp2[b] + dp1[b]-dp1[portals[b]] + c-b), MOD);
        }
        prev = points[i];
    }

    // for (auto x: dp2) {
    //     cout << x.first << ':' << x.second << '\n';
    // }

    ll ans;
    b = prev.first;
    c = prev.first + 1;
    if (prev.second == 0) {
        ans = mod((dp2[b] + c-b), MOD);
    } else {
        ans = mod((dp2[b] + dp1[b]-dp1[portals[b]] + c-b), MOD);
    }

    cout << ans << '\n';
}


int main() {
    FIXIO;
    //fileio();

    ll t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}