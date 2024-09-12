#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int n, x, y, arr[5] = {15, 10, 6, 3, 1};
    while (t--) {
        cin >> n;

        x = 0, y = 0;
        for (int i = 0; i < 5; i++) {
            if (n >= arr[i]) {
                x += (n / arr[i]);
                n %= arr[i];
            }
        }

        cout << x << '\n';

    }

    return 0;
}