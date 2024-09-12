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

    int t;
    cin >> t;

    int n, x, m, li, ri, bgn, end;
    while (t--) {
        cin >> n >> x >> m;
        
        bgn = end = x;
        for (int i = 0; i < m; i++) {
            cin >> li >> ri;

            if (li <= bgn && ri >= end) {
                bgn = li, end = ri;
            } else if (li <= bgn && ri >= bgn) {
                bgn = li;
            } else if (li <= end && ri >= end) {
                end = ri;
            }
        }

        cout << end - bgn + 1 << '\n';
    }

    return 0;
}