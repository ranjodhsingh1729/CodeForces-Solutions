#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int n, m, a, b, x, y, z;
    cin >> n >> m >> a >> b;

    x = n * a;
    y = (n / m) * b + (n % m) * a;
    z = (n / m + 1) * b;

    cout << (x < y ? (x < z ? x : z) : (y < z ? y : z)) << '\n';

}