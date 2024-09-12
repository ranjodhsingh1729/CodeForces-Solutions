#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, x;
    while (t--) {
        cin >> n >> x;
        
        for (int i = 2; i < n; i++) {
            int r = 2*(i-1);
            if ((n % r) == 0 || (n % r) == x) {
                cout << i << ' ' << r << ' ' << n / r << ' '  << n % r << '\n';
            }
        }
        
    }

    return 0;
}