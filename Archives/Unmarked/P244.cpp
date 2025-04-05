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
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << arr[n-1] << ' ';
        for (int i = 0; i < n-1; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        
        
        
    }

    return 0;
}