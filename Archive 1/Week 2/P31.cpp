#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;

    bool flag = true;
    int root = sqrt(x);
    for (int i = 2; i <= root; i++) {
        if (x % i == 0) {
            flag = false; break;
        }
    }

    return flag;
}

int main() {
    int t;
    cin >> t;

    int n, k;
    while (t--) {
        cin >> n >> k;

        int flag = 0;
        for (int i = 1; i <= n/2; i++) {
            if (n % i == 0 && n / i <= k) {
                cout << i << '\n';
                flag = 1; break;
            }
        }

        if (!flag) {
            cout << n << '\n';
        }
    }

    return 0;
}