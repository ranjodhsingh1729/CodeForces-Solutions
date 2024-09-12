#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int n, sum, arr[MAXLEN * 3];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        if (sum % 3 == 0) {
            cout << 0 << '\n';
        } else if (sum % 3 == 2) {
            cout << 1 << '\n';
        } else {
            int i;
            for (i = 0; i < n; i++) {
                if ((sum - arr[i]) % 3 == 0) {
                    break;
                }
            }
            if (i < n) {
                cout << 1 << '\n';
            } else {
                cout << 2 << '\n';
            }
        }


    }

    return 0;
}