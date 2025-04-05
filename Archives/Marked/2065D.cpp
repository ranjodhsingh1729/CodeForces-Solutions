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
    ll n, m;
    cin >> n >> m;
    vector <vector<int>> via(n, vector<int> (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> via[i][j];

    ll sum = 0, tmp; vector <ll> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
        tmp = 0;
        for (int j = 0; j < m; j++) {
            ans[i] += via[i][j];
            tmp += via[i][j] * (m-j);
        }
        ans[i] *= m;
        sum += tmp;
    }
    sort(ans.begin(), ans.end());

    for (int i = 0; i < n; i++) {
        sum += i * ans[i];
    }

    cout << sum << '\n';
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