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

    int n;
    char arr[50][50];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (arr[i][j] == '1' && (arr[i][j+1] == '0' && arr[i+1][j] == '0')) {
                    break;
                }
            }
            if (j != n) {
                break;
            }
        }
        
        if (i == n) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}