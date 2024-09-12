#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    long long a, b, l, m;
    while (t--) {
        cin >> a >> b;

        l = (a*b)/gcd(a, b);

        if (l != b) {
            cout << l << '\n';
        } else if (a == 1) {
            cout << l * l << '\n';
        } else {
            for (int i = 2; i * i <= b; ++i) {
                if (b % i == 0) {
                    m = i; break;
                }
            }
            cout << l * m << '\n';
        }        
        
    }
}