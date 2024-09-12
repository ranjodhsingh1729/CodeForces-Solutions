#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, arr1[500], arr2[500];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                cin >> arr1[(i - 1) / 2];
            } else {
                cin >> arr2[i / 2];
            }
        }

        sort(arr1, arr1 + (n / 2));        
        sort(arr2, arr2 + ((n + 1) / 2));

        int flag = 1, order = arr1[0] > arr2[0];
        for (int i = 0; i < (n / 2); i++) {
            if (order ? arr1[i] < arr2[i] : arr1[i] > arr2[i]) {
                flag = 0; break;
            }
        }

        
    }

    return 0;
}