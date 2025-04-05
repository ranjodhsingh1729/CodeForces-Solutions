#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int n, flag, arr[MAXLEN * 3];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        flag = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 4) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}