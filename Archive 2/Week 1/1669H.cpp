#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void fileio() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

void solve() {
    ll n, k, arr[2*MAXLEN];
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum, brr[31];
    for (int i = 0; i < 31; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            if (!(arr[j] & (1 << i))) {
                sum++;
            }
        }
        brr[i] = sum;
    }

    int mask = 0;
    for (int i = 30; i >= 0; i--) {
        if (k >= brr[i]) {
            k -= brr[i];
            mask = mask | (1 << i);
        }
    }

    int ans = 0x7fffffff;
    for (int i = 0; i < n; i++) {
        ans = ans & arr[i];
    }
    ans = ans | mask;

    cout << ans << '\n';
}


int main() {
    FIXIO;
    //fileio();

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}