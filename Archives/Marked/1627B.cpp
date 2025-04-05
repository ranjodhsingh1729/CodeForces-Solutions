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

    map <int, int> freq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            freq[(
                max(abs(i-1), abs(i-n)) + max(abs(j-1), abs(j-m))
            )]++;
        }
    }

    int temp;
    for (auto &x: freq) {
        temp = x.second;
        while (temp--) {
            cout << x.first << ' ';
        }
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