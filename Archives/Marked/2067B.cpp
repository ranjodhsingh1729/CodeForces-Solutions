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
    ll n, tmp;
    cin >> n;
    vector <int> via(1002, 0);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        via[tmp]++;
    }

    int f = 1;
    for (int i = 1; i <= 1000; i++) {
        if (via[i] == 0) continue;
        if (via[i] == 1) { f = 0; break; }
        
        via[i+1] += via[i]-2, via[i] = 2;
    }

    if (f && via[1001]%2 == 0) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
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