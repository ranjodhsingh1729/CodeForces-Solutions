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

bool verify(int i, int j, int n, char arr[50][50][2]) {
    // cout << i << ' ' << j << ' ' << arr[i][j][0] << ' ' << (bool) arr[i][j][1] << '\n';
    if (arr[i][j][1] == 1) {
        return true;
    } else {
        if (i == n-1 | j == n-1) {
            arr[i][j][1] = 1; return true;
        } else {
            if (arr[i][j+1][0] == '1') {
                arr[i][j][1] = 1; return verify(i, j+1, n, arr);
            } else if (arr[i+1][j][0] == '1') {
                arr[i][j][1] = 1; return verify(i+1, j, n, arr);
            } else {
                return false;
            }
        }
    }
}

bool solve(int n, char arr[50][50][2]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j][0] == '1') {
                if (!(verify(i, j, n, arr))) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    init_io();

    int t;
    cin >> t;

    int n;
    char arr[50][50][2];
    while (t--) {
        cin >> n;
        char temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> temp;
                arr[i][j][0] = temp, arr[i][j][1] = 0;
            }
        }
        
        bool ans = solve(n, arr);
        if (ans) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

    }

    return 0;
}