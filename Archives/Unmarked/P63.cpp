#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int max_pieces(int n, int arr[]) {
    float k;
    int i, j, max = INT_MIN;
    for (i = 0; i <= n/arr[2]; i++) {
        for (j = 0; j <= n/arr[1]; j++) {
            k = (float) (n - i * arr[2] - j * arr[1]) / arr[0];

            if(floor(k) == ceil(k)) {
                if (i + j + k > max) max = i + j + k;
            }
        }
    }

    return max;
}

int main() {
    int n, arr[3];
    cin >> n;

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+3);

    cout << max_pieces(n, arr) << '\n';
}