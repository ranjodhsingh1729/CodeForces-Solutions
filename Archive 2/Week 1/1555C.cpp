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
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum1 += arr[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> brr[i];
            // Contructed Dynamically :)
        }

        sum1 -= arr[0];
        ll best = sum1;
        for (int i = 1; i < n; i++) {
            sum1 -= arr[i];
            sum2 += brr[i-1];
            best = min(best, max(sum1, sum2));
        }
        cout << best << '\n';
    }

    return 0;
}