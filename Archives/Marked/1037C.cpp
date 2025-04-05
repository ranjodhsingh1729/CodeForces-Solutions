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
    ll n;
    cin >> n;
    char arr[10*MAXLEN], brr[10*MAXLEN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] -= '0';
    }
    for (int i = 0; i < n; i++) {
        cin >> brr[i];
        brr[i] -= '0';
    }

    int cost = 0;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] != brr[i]) {
            if (arr[i] == brr[i+1] && arr[i+1] == brr[i]) {
                arr[i] = brr[i];
                arr[i+1] = brr[i+1];
            }
            cost++;
        }
    }
    if (arr[n-1] != brr[n-1]) {
        cost++;
    }

    cout << cost << '\n';

}


int main() {
    FIXIO;
    //fileio();

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}