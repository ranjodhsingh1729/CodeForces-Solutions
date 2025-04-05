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

    int n, arr[MAXLEN];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int i, l, r, ttot;
        int tur, ctot, atot, btot;

        l = 0, r = n;
        tur = ctot = atot = btot = 0;
        while (l != r) {
            ttot = 0;

            if (tur % 2 == 0) {
                for (i = l; i < r && ttot <= ctot; i++)
                    ttot += arr[i];
                atot += ttot;
                l = i;
            } else {
                for (i = r-1; i >= l && ttot <= ctot; i--)
                    ttot += arr[i];
                btot += ttot;
                r = i+1;
            }

            tur++;
            ctot = ttot;

            // cout << tur << ' ' << l << ' ' << r << ' ' << ctot << '\n';
        }

        cout << tur << ' ' << atot << ' ' << btot << '\n';
    }

    return 0;
}