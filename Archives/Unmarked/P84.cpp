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

    int n, a, b, c, root, flag, temp;
    while (t--) {
        cin >> n;

        root = sqrt(n), flag = 0, a = 0, b = 0;
        for (int i = 2; i <= root; i++) {
            if (n % i == 0) {
                if (flag) {
                    temp = a * i;
                    if (n % temp == 0 && (n / temp != a && n / temp != i)) {
                        b = i;
                        flag = 2; break;
                    }
                } else {
                    a = i;
                    flag = 1;
                }
            }
        }

        if (flag == 2) {
            cout << "YES" << '\n';
            cout << a << ' ' << b << ' ' << n/(a*b) << '\n';            
        } else {
            cout << "NO" << '\n';
        }
    }

}