#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    double n;
    while (t--) {
        cin >> n;

        double angle = 3.14159265358979323846L / n;
        cout << setprecision(12) << 1 / tan(angle / 2) << ' ' << 1 / sin(angle / 2) << ' ' << 1 / sin(angle / 2) - 1 / tan(angle / 2) << '\n';
    }

    return 0;
}