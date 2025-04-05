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
    vector <int> via(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> via[i];
    }

    pair<int,int> ans = {1,1};
    int a, b, mx = 0;
    for (int i = 0; i < n-1; i++) {
        a = 0, b = 0;
        for (int j = i+1; j < n; j++) {
            if (via[j] > via[i]) {
                a++;
            }
            if (via[j] < via[i]) {
                b++;
            }
            if (mx < b-a) {
                mx = b-a;
                ans = {i+1, j+1};
            }
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
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