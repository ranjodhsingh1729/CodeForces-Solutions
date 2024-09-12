#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

void init_io() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

int main() {
    init_io();

    ll n, m;
    cin >> n >> m;

    ll x, y;
    x = min(n, m);
    y = max(n, m);

    if (2*x <= y) {
        cout << x << '\n';
    } else {
        cout << (x+y)/3LL << '\n';
    }

    return 0;
}