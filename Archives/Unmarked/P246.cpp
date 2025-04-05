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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    init_io();

    int t;
    cin >> t;

    set <int> RG1, RG2, IT1;
    int l, r, L, R;
    while (t--) {
        RG1.clear();
        RG2.clear();
        IT1.clear();

        cin >> l >> r >> L >> R;
        
        int x = (l == L) + (l == R) + (r == L) + (r == R);

        for (int i = l; i <= r; i++) {
            RG1.insert(i);
        }
        for (int i = L; i <= R; i++) {
            RG2.insert(i);
        }

        set_intersection(RG1.begin(), RG1.end(), RG2.begin(), RG2.end(), inserter(IT1, IT1.begin()));
        
        
        int o = IT1.size();
        switch (x)
        {
        case 0:
            cout << o + 1 << '\n';
            break;
        case 1:
            if (o == 1) {
                cout << 2 << '\n';
            } else {
                cout << o << '\n';
            }
            break;
        case 2:
            cout << o - 1 << '\n';
            break;
        default:
            cout << "ERROR" << '\n';
            break;
        }

    }

    return 0;
}