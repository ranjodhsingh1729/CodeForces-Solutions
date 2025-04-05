#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int count, arr[5];
    while (t--) {
        for (int i = 0; i < 5; i++) {
            cin >> arr[i];
        }

        count = 0;
        for (int i = 0; i < 5; i++) {
            if (arr[i] == 1) count++;
        }

        if (count >= 4) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}