#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int a, b;
    int n, q, arr[MAXLEN * 3];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cin >> q;
        while (q--) {
            cin >> a >> b;

            int i;
            for (i = a; i <= b-1; i++) {
                if (arr[a-1] != arr[i]) {
                    cout << a << ' ' << i+1 << '\n'; break; 
                }
            }

            if (i == b) {
                cout << -1 << ' ' << -1 << '\n';
            }
        }
        
        
    }

    return 0;
}