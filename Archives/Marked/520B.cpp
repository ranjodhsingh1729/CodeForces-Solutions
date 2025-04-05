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


int solve(int n, int m) {
    if (m <= n) {
        return n-m;
    } else {
        return 1 + m%2 + solve(n, (m+1)/2);
    }
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    // cin >> t;

    ll n, m;
    while (t--) {
        cin >> n >> m;
        cout << solve(n, m) << '\n';
    }

    return 0;
}