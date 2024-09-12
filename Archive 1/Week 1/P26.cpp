#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;


int main() {
    int t;
    cin >> t;

    int n, q;
    char arr[MAXLEN * 3];
    while (t--) {
        cin >> n >> q;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int curr = 1, best = 1; // can not use INT_MIN as loop doesn't run for n = 1
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i-1]) {
                curr++;
            } else {
                curr = 1;
            }
            best = max(curr, best);
        }

        cout << best << ' ';

        for (int i = 0; i < q; i++) {
            cin >> arr[n+i];

            if (arr[n+i] == arr[n+i-1]) {
                curr++;
            } else {
                curr = 1;
            }
            best = max(curr, best);

            cout << best << ' ';
        }

        cout << '\n';
    }
}