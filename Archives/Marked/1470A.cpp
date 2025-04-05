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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init_io();

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[n], brr[m];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < m; i++)
            cin >> brr[i];

        sort(arr, arr+n, greater<int>{});

        ll cost = 0;
        for (int i = 0; i < n; i++) {
            if (i < m && brr[i] < brr[arr[i]-1]) {
                cost += brr[i];
            } else {
                cost += brr[arr[i]-1];
            }
            
        }

        cout << cost << '\n';
    }

    return 0;
}
