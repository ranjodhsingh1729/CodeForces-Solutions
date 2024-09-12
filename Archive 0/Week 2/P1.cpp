#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, l, r, flag;
    string w;
    while (t--) {
        cin >> n;
        cin >> w;

        l = r = 0;
        for (int i = 0; i < n; i++) {
            if (w[i] == 'B') {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i > 0 - 1; i--) {
            if (w[i] == 'B') {
                r = i;
                break;
            }
        }
        
        cout << r - l + 1 << '\n';
    }

    return 0;
}