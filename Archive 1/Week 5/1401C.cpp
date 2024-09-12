#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

void init_io() {
    #ifndef ONLINE_JUDGE
    freopen("streams/input.txt", "r", stdin);
    freopen("streams/output.txt", "w", stdout);
    #endif
}

int main() {
    init_io();

    int t;
    cin >> t;

    int n, arr[MAXLEN], brr[MAXLEN];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            brr[i] = arr[i];
        }
        sort(brr, brr+n);

        int mnm = *min_element(arr, arr+n);

        int i;
        for (i = 0; i < n; i++) {
            if (arr[i] % mnm != 0 && arr[i] != brr[i]) {
                break;
            }
        }
        if (i == n) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}