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
    int arr[MAXLEN];
    int temp, root, factors;
    while (t--) {
        cin >> n >> k;

        if (n % k == 0) {
            cout << n/k << '\n';
        } else {
            if (k >= n) {
                cout << 1 << '\n';
            } else {
                arr[0] = 1;
                factors = 1, root = sqrt(n);
                for (int i = 2; i <= root; i++) {
                    if (n % i == 0) arr[factors++] = i;
                }
                temp = factors;
                for (int i = 0; i < temp; i++) {
                    arr[factors++] = n / arr[temp - i - 1];
                }

                int l = 0, h = factors, p;
                while (h - l > 1) {
                    p = (h + l) / 2;
                    if (k > arr[p]) {
                        l = p;
                    } else if (k < arr[p]) {
                        h = p;
                    } else {
                        cout << "ERROR" << '\n';
                    }
                }

                cout << n/arr[l] << '\n';
            }
        }

    }

    return 0;
}