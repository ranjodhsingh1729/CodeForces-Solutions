#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

void solve(int n) {
    for (int i = 1; i <= 26; i++) {
        for (int j = i; j <= 26; j++) {
            if (n - (i + j) <= 26) {
                cout << (char) (96 + i) << (char) (96 + j) << (char) (96 + n - i - j) << '\n'; return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    int n;
    while (t--) {
        cin >> n;

        solve(n);
    }

    return 0;
}