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
    ll n, l, r;
    cin >> n >> l >> r;
    int arr[MAXLEN];
    int brr[MAXLEN];
    int crr[MAXLEN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        brr[i] = arr[i];
        crr[i] = arr[i];
    }
    sort(brr, brr+r);
    sort(crr+l-1, crr+n);

    
    ll sum1 = 0;
    for (int i = 0; i < r-l+1; i++) {
        sum1 += brr[i];
    }
    
    ll sum2 = 0;
    for (int i = l-1; i < r; i++) {
        sum2 += crr[i];
    }
    
    cout << min(sum1, sum2) << '\n';
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