#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n;
    while (t--) {
        cin >> n;

        cout << (n + 1) / 2 << ' ' << (n + 1) / 2 - 1 << '\n';
    }

    return 0;
}