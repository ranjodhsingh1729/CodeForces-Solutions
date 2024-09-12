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

        for (int i = 1; i <= n; i++) {
            int sum = 0, count = 1;
            for (int j = 0; j < n; j++) {
                sum += arr[j];
                if (sum == i) {
                    count++;
                } else if (sum > i) {
                    continue;
                }
            }
        }

    }

    return 0;
}