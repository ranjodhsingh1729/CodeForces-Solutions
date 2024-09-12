#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    long long p;
    string commands;
    int n, m, arr[2 * MAXLEN];
    while (t--) {
        cin >> n >> m;

        p = 1;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            p *= arr[i];
        }

        cin >> commands;

        int l = 0, r = n - 1, el;
        for (int i = 0; i < n; i++) {
            cout << p % m << ' ';

            if (commands[i] == 'L') {
                p /= arr[l++];
            } else {
                p /= arr[r--];
            }
        }

        cout << '\n';
    }

    return 0;
}