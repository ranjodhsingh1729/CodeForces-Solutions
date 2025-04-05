#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    double r1;
    long long n;
    while (t--) {
        cin >> n;

        if (n == 1) {
            cout << "NO" << '\n'; continue;
        }

        r1 = sqrt(n);

        if (floor(r1) == ceil(r1)) {
            int f = 0, r2 = sqrt(r1);
            for (int i = 2; i <= r2; i++) {
                if ((int) r1 % i == 0) {
                    f = 1; break;
                }
            }
            if (f) {
                cout << "NO" << '\n';
            } else {
                cout << "YES" << '\n';
            }
        } else {
            cout << "NO" << '\n';
        }

    }

}