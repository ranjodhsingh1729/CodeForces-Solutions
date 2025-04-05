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
    int n, k;
    string a, b;
    while (t--) {
        cin >> n;
        cin >> a >> b;

        k = 0;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                k+=3;

        cout << k << ' ';
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                cout << i+1 << ' ' << 1 << ' ' << i+1 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}