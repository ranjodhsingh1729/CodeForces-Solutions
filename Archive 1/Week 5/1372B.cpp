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

int leasprimefactor(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return i;
        }
    }
    return x;
}

int main() {
    init_io();

    int t;
    cin >> t;

    int a, b, n;
    while (t--) {
        cin >> n;
        a = n / leasprimefactor(n);
        b = n - a;
        cout << a << ' ' << b << '\n';
    }

    return 0;
}