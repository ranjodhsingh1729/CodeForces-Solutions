#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int n, m, arr[MAXLEN * 3];
    while (t--) {
        cin >> n >> m;

        if ((m - n + 1) % 2 == 0) {
            int f = n % 2;
            for (int i = n; i <= m; i++) {
                cout << (f == i % 2 ? i + 1 : i - 1) << ' ';
            }
            cout << '\n';
        } else {
            if (gcd(n, m) == 1) {
                cout << m << ' ' << n << ' ';
                int f = (n+2) % 2;
                for (int i = n+2; i <= m-1; i++) {
                    cout << (i % 2 == f ? i + 1 : i - 1) << ' ';
                }
                cout << n + 1 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}