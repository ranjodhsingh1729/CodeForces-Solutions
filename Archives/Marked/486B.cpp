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
    ll n, m, arr[101][101], brr[101][101];

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int tmpr, tmpc;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                tmpr = tmpc = 1;

                for (int c = 0; c < n; c++) {
                    tmpr = tmpr && arr[c][j];
                }
                for (int c = 0; c < m; c++) {
                    tmpc = tmpc && arr[i][c];
                }

                if (!(tmpr || tmpc)) {
                    cout << "NO" << '\n';
                    return;
                }

                brr[i][j] = tmpr && tmpc;   
            } else {
                brr[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmpr = tmpc = 0;
            for (int c = 0; c < n; c++) {
                tmpr = tmpr || brr[c][j];
            }
            for (int c = 0; c < m;  c++) {
                tmpc = tmpc || brr[i][c];
            }

            if (arr[i][j] != (tmpr || tmpc)) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << brr[i][j] << ' ';
        }
        cout << '\n';
    }
    
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