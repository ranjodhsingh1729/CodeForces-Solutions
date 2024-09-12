#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, arr[MAXLEN];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int period = 0;
        for (int i = 0; i < n; i++) {
            period = (arr[i] * (period / arr[i] + 1));
        }

        cout << period << '\n';
    }

    return 0;
}