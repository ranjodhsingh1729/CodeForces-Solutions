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

    ll t;
    cin >> t;

    ll n, arr[2*MAXLEN];
    ll k, brr[2*MAXLEN];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        k = 0;
        brr[k++] = arr[0];
        for (int i = 1; i < n-1; i++) {
            if (!((arr[i] < arr[i-1]) ^ (arr[i] < arr[i+1]))) {
                brr[k++] = arr[i];
            }
        }
        brr[k++] = arr[n-1];

        cout << k << '\n';
        for (int i = 0; i < k; i++) {
            cout << brr[i] << ' ';
        }
        cout << '\n';
        
    }

    return 0;
}