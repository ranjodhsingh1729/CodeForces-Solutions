#include <bits/stdc++.h>

#define MAXLEN 100001
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
    map <int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int ans[2*MAXLEN] = { 0 };

    int m = 0;
    for (auto &x : freq) {
        arr[m++] = x.first;
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ans[arr[i]]) continue;
        for (int j = 1; j*arr[i] <= k; j++) {
            if (!ans[j*arr[i]]) {
                cnt++;
                ans[j*arr[i]] = 1;
            }
        }
    }

    cout << cnt << '\n';
}


int main() {
    // FIXIO;   
    //fileio();

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}