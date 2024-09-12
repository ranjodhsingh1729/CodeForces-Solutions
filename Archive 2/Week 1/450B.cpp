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

int main() {
    init_io();

    int x, y, n;
    cin >> x >> y >> n;

    int ans;
    n = n - 1;
    n = n % 6;
    if (n == 0) {
        ans = x;
    } else if (n == 1) {
        ans = y;
    } else if (n == 2) {
        ans = y - x;
    } else if (n == 3) {
        ans = -x;
    } else if (n == 4) {
        ans = -y;
    } else if (n == 5) {
        ans = x - y;
    }
    cout << (ans > 0 ? ans % 1000000007 : ((ans % 1000000007) + 1000000007) % 1000000007) << '\n';


    return 0;
}