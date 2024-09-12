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

    int n, arr[MAXLEN * 3];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        int l, h;
        ll sum, best;
        l = 0, h = -1;
        sum = best = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= sum+arr[i]) {
                sum = arr[i];
                l = i;
            } else {
                sum += arr[i];
            }
            if (sum > best) {
                h = i;
                best = sum;
            }
        }

        cout << l << ' ' << h << ' ' << best << '\n';

        if (l == 0 && h == n-1) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}