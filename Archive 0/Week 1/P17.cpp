#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int n, m;
    long long arr_n[MAXLEN], arr_ns[MAXLEN];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr_n[i];
        arr_ns[i] = arr_n[i];
    }


    sort(arr_ns, arr_ns+n);
    for (int i = 1; i < n; i++) {
        arr_n[i] += arr_n[i-1];
        arr_ns[i] += arr_ns[i-1];
    }    

    // for (int i = 0; i < n; i++) {
    //     cout << arr_n[i] << ':' << arr_ns[i] << '\n';
    // }

    cin >> m;
    int t, l, r;
    for (int i = 0; i < m; i++) {
        cin >> t >> l >> r;
        if (t == 1) {
            cout << arr_n[r-1] - (l-2 < 0 ? 0 : arr_n[l-2]) << '\n';
        }
        if (t == 2) {
            cout << arr_ns[r-1] - (l-2 < 0 ? 0 : arr_ns[l-2]) << '\n';
        }
    }        
    

}