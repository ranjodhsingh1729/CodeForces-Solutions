#include <bits/stdc++.h>

#define MAXLEN 100000
// #define abs(a) ((a) >= 0 ? (a) : -(a))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;


void fileio() {
    #ifndef ONLINE_JUDGE
    freopen("./.streams/input.txt", "r", stdin);
    freopen("./.streams/output.txt", "w", stdout);
    freopen("./.streams/output.txt", "w", stderr);
    #endif
}

void solve() {
    ll n, m, k, arr[2*MAXLEN], brr[2*MAXLEN];

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
        cin >> brr[i];

    sort(arr, arr+n);
    sort(brr, brr+m);

    ll a, b, c;
    a = b = c = 0;

    int i = 0, j = 0, x = 0;
    while (x++ < k) {
        while (i < n && arr[i++] < x);
        i--;
        while (j < m && brr[j++] < x);
        j--;

        if (arr[i] == x && brr[j] == x) {
            c++;
        } else {
            if (arr[i] == x)
                a++;
            if (brr[j] == x)
                b++;
        }
    }

    if ((a+b+c) == k && (a <= k/2) && (b <= k/2)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

}


int main() {
    FIXIO
    fileio();

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}