#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

void init_io() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    init_io();


    ll t;
    cin >> t;

    ll l, m, temp;
    ll n, k, arr[2*MAXLEN];
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        temp = arr[0], arr[0] = 0;
        for (int i = 1; i < n-1; i++) {
            if (arr[i] > temp && arr[i] > arr[i+1]) {
                temp = arr[i], arr[i] = 1;
            } else {
                temp = arr[i], arr[i] = 0;
            }
        }
        arr[n-1] = 0;

        for (int i = 1; i < n; i++) {
            arr[i] += arr[i-1];
        }

        l = m = 0;
        for (int i = 0; i <= n-k; i++) {
            temp = (arr[i+k-1]  - arr[i] - (arr[i+k-1] > arr[i+k-2]));
            if (m < temp) {
                m = temp;
                l = i;
            }
        }

        cout << m+1 << ' ' << l+1 << '\n';
        
    }

    return 0;
}