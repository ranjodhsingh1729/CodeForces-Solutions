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

        int cnt = 0, best = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (arr[i] == arr[0]) {
                cnt++;
            } else {
                best = min(best, cnt);
                cnt = 0;
            }
        }

        if (best != INT_MAX) {
            best = min(best, cnt);
            cout << best << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}