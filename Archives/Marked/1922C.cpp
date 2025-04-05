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
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool f;
    int forward[2*MAXLEN];
    int backward[2*MAXLEN];
    forward[0] = 0;
    forward[1] = 1;
    for (int i = 2; i < n; i++) {
        f = arr[i]-arr[i-1] < arr[i-1]-arr[i-2];
        if (f) {
            forward[i] = forward[i-1] + 1;
        } else {
            forward[i] = forward[i-1] + arr[i]-arr[i-1];
        }
    }

    backward[n-1] = 0;
    backward[n-2] = 1;
    for (int i = n-3; i >= 0; i--) {
        f = arr[i+1]-arr[i] < arr[i+2]-arr[i+1];
        if (f) {
            backward[i] = backward[i+1] + 1;
        } else {
            backward[i] = backward[i+1] + arr[i+1]-arr[i];
        }
    }

    ll m;
    cin >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        
        f = a < b;
        if (f) {
            cout << forward[b-1]-forward[a-1] << '\n';
        } else {
            cout << backward[b-1]-backward[a-1] << '\n';
        }
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