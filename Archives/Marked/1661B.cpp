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


int calc(int x) {
    int mn = 15, cnt = 0, y;
    for (int i = 0; i <= 15; i++) {
        y = (x+i)%(1<<15), cnt = i;

        for (int j = 0; y && j < 15; j++) {
            y *= 2;
            y %= (1<<15);

            cnt++;
        }

        mn = min(mn, cnt);
    }

    return mn;
}


void solve() {
    ll n, arr[2*MAXLEN];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {    
        cout << calc(arr[i]) << ' ';
    }

    cout << '\n';

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