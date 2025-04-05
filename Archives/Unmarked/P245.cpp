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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    init_io();

    ll t;
    cin >> t;

    ll n, arr[40];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        if (n == 2 && abs(arr[0]-arr[1]) != 1) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        
        
    }

    return 0;
}