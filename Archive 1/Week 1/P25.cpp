#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, k, waste, arr[MAXLEN * 3];
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        waste = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= k && arr[i] % k < waste) {
                waste = arr[i] % k;
            }
        }

        if (waste == INT_MAX) {
            cout << -1 << '\n';
        } else {
            cout << waste << '\n';
        }
    }
    
    return 0;
}