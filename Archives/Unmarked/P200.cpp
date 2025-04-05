#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    ll n, x;
    while (t--) {
        cin >> n;
        cout << 2*n + (n+1)*(n-2)/2 << '\n';
    }

    return 0;
}