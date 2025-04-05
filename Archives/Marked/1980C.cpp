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
    ll n, arr[2*MAXLEN], brr[2*MAXLEN];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        cin >> brr[i];

    ll m, crr[2*MAXLEN];
    map <int, int> freqc;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> crr[i];
        freqc[crr[i]]++;
    }

    map <int, int> freqd;
    for (int i = 0; i < n; i++) {
        if (arr[i] != brr[i]) {
            freqd[brr[i]]++;
        }
    }

    for (auto &x: freqd) {
        if (x.second > freqc[x.first]) {
            cout << "NO" << '\n';
            return;
        }
    }

    sort(brr, brr+n);
    if (binary_search(brr, brr+n, crr[m-1]) > 0) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

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