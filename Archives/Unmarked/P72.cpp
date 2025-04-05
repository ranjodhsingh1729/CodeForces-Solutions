#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    long long n, k;
    while (t--) {
        cin >> n >> k;

        long long lim_k = ceil((1.0 + sqrt(1 + 8*k)) / 2.0);
        long long lim_n = (lim_k*(lim_k-1)/2.0);

        for (int i = 0; i < (n - lim_k); i++) {
            cout << 'a';
        }

        cout << 'b';

        for (int i = 0; i < (lim_n - k); i++) {
            cout << 'a';
        }

        cout << 'b';

        for (int i = 0; i < (lim_k - lim_n + k - 2); i++) {
            cout << 'a';
        }

        cout << '\n';
    }

    return 0;
}