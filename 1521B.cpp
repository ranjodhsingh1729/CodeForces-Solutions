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

    int n, arr[MAXLEN];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int mni = 0, mnv = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < mnv) {
                mni = i;
                mnv = arr[i];
            }
        }

        cout << n-1 << '\n';
        for (int i = 0; i < n; i++) {
            if (i != mni) {
                cout << mni+1 << ' ' << i+1 << ' ' << mnv << ' ' << mnv + abs(i-mni) << '\n';
            }
        }
    }

    return 0;
}