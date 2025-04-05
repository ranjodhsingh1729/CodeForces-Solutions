#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int n, arr[MAXLEN * 3];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int flag, curr, best;

        flag = 1, curr = -1; best = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (flag) {
                if (arr[i] != arr[0]) {
                    best = min(best, i - curr - 1);
                    curr = i;
                }
            } else {
                if (arr[i] == arr[0]) {
                    flag = 1;
                }
            }
        }


        if (best != INT_MAX) {
            best = min(best, n - curr - 1);
            cout << best << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}