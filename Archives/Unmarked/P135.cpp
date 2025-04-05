#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, arr[MAXLEN * 2];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        
        int fb = 0;
        for (int i = 0 ; i < n; i++) {
            if (arr[i] == arr[0]) {
                fb++;
            } else {
                break;
            }
        }

        int fe = 0;
        for (int i = n - 1; i > 0 - 1; i--) {
            if (arr[i] == arr[n-1]) {
                fe++;
            } else {
                break;
            }
        }

        // cout << fb << ' ' << fe << '\n';

        if (fb == n || fe == n) {
            cout << 0 << '\n';
        } else {
            if (arr[0] == arr[n-1]) {
                cout << n - fb - fe << '\n';
            } else {
                if (fb >= fe) {
                    cout << n - fb << '\n';
                } else {
                    cout << n - fe << '\n';
                }
            }
        }
    }

    return 0;
}