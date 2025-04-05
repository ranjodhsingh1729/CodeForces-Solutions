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

    int i, j, k;
    for (i = 0; i <= n/arr[2]; i++) {
        for (j = 0; j <= n/arr[1]; j++) {
            for (k = 0; k <= n/arr[0]; k++) {
                if (n == (i * arr[2] + j * arr[1] + k * arr[0])) {
                    cout << i + j + k << '\n';
                    return 0;
                }
            }
        }
    }   
}