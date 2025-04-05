#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    double n, m, k;
    while (t--) {
        cin >> n >> m >> k;

        int r = ceil(n / m);

        if (r + k >= n)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }

    return 0;
}