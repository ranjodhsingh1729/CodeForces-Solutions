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
    ll n, arr[2*MAXLEN];
    map <int, int> freq;

    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        freq[arr[i]]++;
    }
    sort(arr, arr+n);

    if (n <= 2) {
        cout << -1 << '\n';
        return;
    }

    int md = (n/2);
    ll target = arr[md];

    ll x = 2*n*target-sum;

    if (x < 0) {
        cout << 0 << '\n';
    } else {
        cout << x+1 << '\n';
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