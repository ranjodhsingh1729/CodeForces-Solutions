#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, arr[MAXLEN * 2];
    while (t--) {
        cin >> n;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        int avg = sum / n;

        for (int i = 0; i < n; i++) {
            arr[i] -= avg;
        }

        for (int i = 1; i < n; i++) {
            arr[i] += arr[i-1];
        }

        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
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