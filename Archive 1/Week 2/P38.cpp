#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

// int result(int c, int n) {
//     if (n == 0) {
//         return 2;
//     } else if (n == 1) {
//         return c;
//     } else {
//         return result(c, n-1) * c - result(c, n-2);
//     }
// }

int main() {
    int t;
    cin >> t;

    long long n, c, x;
    while (t--) {
        cin >> n >> c;

        long long temp;
        long long r1 = 2;
        long long r2 = c;
        for (int i = 2; i <= n; i++) {
            temp = (r2 * c - r1) % (1000000007);
            r1 = r2; r2 = temp;
        }

        cout << r2 % 1000000007 << '\n';

    }

    return 0;
}