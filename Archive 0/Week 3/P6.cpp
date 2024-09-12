#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, k, count, init, shape;
    char grid[10][10], pattern[10];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        k = 0;
        for (int i = 0; i < n; i++) {
            count = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') count++;
            }
            if (count) {
                pattern[k++] = count;
            }
        }

        
        init = pattern[0], shape = 1;
        for (int i = 1; i < k; i++) {
            if (pattern[i] != init) {
                shape = 0; break;
            }
        }
        
        if (shape) {
            cout << "SQUARE" << '\n';
        } else {
            cout << "TRIANGLE" << '\n';
        }
    }

    return 0;
}