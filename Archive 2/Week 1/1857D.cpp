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
    ll n, arr[2*MAXLEN], brr[2*MAXLEN], crr[2*MAXLEN];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        cin >> brr[i];
    
    int k, best;
    
    best = arr[0]-brr[0];
    k = 0;
    crr[k++] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] - brr[i] == best) {
            crr[k++] = i+1;
        }

        if (arr[i] - brr[i] > best) {
            best = arr[i] - brr[i];
            k = 0;
            crr[k++] = i+1;
        }
    }

    cout << k << '\n';
    for (int i = 0; i < k; i++) {
        cout << crr[i] << ' ';
    }
    cout << '\n';

    
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