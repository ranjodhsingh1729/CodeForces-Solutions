#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;



int main() {
    int n, arr[3];
    cin >> n;

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+3);

    int i, j, k, max = INT_MIN;
    for (i = 0; i <= n/arr[2]; i++) {
        for (j = 0; j <= n/arr[1]; j++) {
            for (k = 0; k <= n/arr[0]; k++) {
                if (n == (i * arr[2] + j * arr[1] + k * arr[0])) {
                    if (i + j + k > max) max = i + j + k;
                }
            }
        }
    }

    cout << max << '\n';
}