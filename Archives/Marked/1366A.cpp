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

    int t;
    cin >> t;

    int a, b;
    while (t--) {
        cin >> a >> b;

        int ans, eql;
        int minn = min(a, b);
        int diff = max(a, b) - min(a, b);
        
        if (diff < minn) {
            ans = diff;
            eql = minn - diff;
            ans += (eql / 3) * 2;
            ans += eql % 3 == 2 ? 1 : 0;
        } else {
            ans = minn;
        }

        cout << ans << '\n';
    }

    return 0;
}