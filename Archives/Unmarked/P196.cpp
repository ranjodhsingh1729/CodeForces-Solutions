#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    map <int, pair <int, int>> pm;

    int t;
    cin >> t;

    int n, m, arr[MAXLEN];
    while (t--) {
        cin >> n >> m;

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                pm[2*sum-arr[i]-arr[j]] = make_pair(i, j);
            }
        }


        int q;
        for (int x = 0; x < m; x++) {
            cin >> q;

            if (pm.find(q) != pm.end()) {
                cout << arr[pm[q].first] << ' ';
                for (int i = 0; i < n; i++) {
                    if (i != pm[q].first && i != pm[q].second) {
                        cout << arr[i] << ' ';
                    }
                }
                cout << arr[pm[q].second] << '\n';
            } else {
                cout << -1 << '\n';
            }

            // cout << pm[q].first << ' ' << pm[q].second << '\n';

        }

    
        
        
    }

    return 0;
}