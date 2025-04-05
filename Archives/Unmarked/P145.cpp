#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int diff;
    string p, c;
    int n, key[MAXLEN];
    while (t--) {
        cin >> n;
        cin >> p;
        cin >> c;

        for (int i = 0; i < p.length(); i++) {
            if (p[i] <= c[i]) {
                diff = c[i] - p[i];
                if (diff % 3 == 0) {
                    key[i] = diff / 3;
                } else if (diff % 3 == 1) {
                    key[i] = (diff + 26) / 3;
                } else if (diff % 3 == 2) {
                    key[i] = (diff + 53) / 3;
                }
            } else {
                diff = 26 + c[i] - p[i];
                if (diff % 3 == 0) {
                    key[i] = diff / 3;
                } else if (diff % 3 == 1) {
                    key[i] = (diff + 26) / 3;
                } else if (diff % 3 == 2) {
                    key[i] = (diff + 53) / 3;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << key[i] << ' ';
        }

        cout << '\n';
        
    }

    return 0;
}