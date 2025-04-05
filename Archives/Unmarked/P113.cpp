#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    unordered_map <int, int> freq_n;
    unordered_map <int, int> freq_m;

    int t;
    cin >> t;

    int flag;
    int p, q, r;
    int n, m, k, arr_n[MAXLEN * 2], arr_m[MAXLEN * 2];
    while (t--) {
        freq_n.clear();
        freq_m.clear();

        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            cin >> arr_n[i];
            freq_n[arr_n[i]]++;
        }
        for (int i = 0; i < m; i++) {
            cin >> arr_m[i];
            freq_m[arr_m[i]]++;
        }

        p = q = r = 0; flag = 0;
        for (int i = 1; i <= k; i++) {
            if (freq_n[i] && freq_m[i]) {
                r++;
            } else if (freq_n[i]) {
                p++;
            } else if (freq_m[i]) {
                q++;
            } else {
                flag = 1; break;
            }
        }

        if (flag) {
            cout << "NO" << '\n';
        } else {
            if (p == q && r % 2 == 0) {
                cout << "YES" << '\n';
            } else if (p != q && r == abs(p - q)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}
