#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n;
    cin >> n;

    ll c = 0, arr[100];
    int k = floorl(log2l(n)+1);
    for (int i = k-1; i >= 0; i--) {
        if (n & (1LL << i)) {
            arr[c++] = (n ^ (1LL << i));
        }
    }
    arr[c++] = n;

    if (arr[0] == 0) {
        cout << 1 << '\n';
        cout << n << '\n';
    } else {
        cout << c << '\n';
        for (int i = 0; i < c; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
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