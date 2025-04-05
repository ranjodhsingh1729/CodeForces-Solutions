#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n;
    char temp;
    int arr[2][2*MAXLEN];
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr[0][i] = temp == '>' ? 1 : 0;
        arr[0][i] = (i % 2 == 0) || arr[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr[1][i] = temp == '>' ? 1 : 0;
        arr[1][i] = ((i+1) % 2 == 0) || arr[1][i];
    }

    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int r = 0, f = 1;;
    for (int i = 0; i < n-2; i++) {
        if (!arr[r][i+1]) {
            if (arr[!r][i] && arr[!r][i+1]) {
                r = !r;
            } else {
                f = 0;
                break;
            }
        }
    }

    if (f && !r && !(arr[r][n-1] || arr[!r][n-2])) {
        f = 0;
    }


    if (f) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }


    
}


int main() {
    FIXIO;

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}