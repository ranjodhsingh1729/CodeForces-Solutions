#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n, k;
    cin >> n >> k;
    int a, b, arr[1001] = { 0 };
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        arr[a]++; arr[b]++;
    }

    int unq = -1;
    for (int i = 1; i <= n; i++) {
        if (!arr[i]) {
            unq=i; break;
        }
    }
    
    cout << n-1 << '\n';
    for (int i = 1; i <= n; i++) {
        if (i == unq) continue;
        cout << unq << ' ' << i << '\n';
    }
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