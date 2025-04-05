#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

void init_io() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

int main() {
    init_io();

    int t;
    cin >> t;

    ll k, a, b;
    int n, l, r, arr[4*MAXLEN];
    while (t--) {
        cin >> n;
        cin >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        b = k/2;
        a = ((k%2) ? b+1 : b);
        l = 0, r = n;


        while (a && (l < n)) {
            if (a > arr[l]) {
                a -= arr[l++], arr[l-1] = 0;
            } else if (a < arr[l]) {
                arr[l] -= a, a = 0;
            } else {
                a = arr[l++] = 0;
                break;
            }
        }
        while (b && (r > 0)) {
            if (b > arr[r-1]) {
                b -= arr[--r], arr[r] = 0;
            } else if (b < arr[r-1]) {
                arr[r-1] -= b, b = 0;
            } else {
                a = arr[--r] = 0;
                break;
            }
        }

        cout << (l < r ? l+n-r : n) << '\n';
    }

        
    return 0;
}