#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

bool solve(int s, int k, map <int, int> monsters) {
    int x = 0, b = 0;
    auto m = monsters.begin();

    while (m != monsters.end()) {
        if (x < m->first) {
            if (m->second > (k - b)) {
                m->second -= (k - b);
                b = 0; x++; continue;
            } else {
                b += m->second; m->second = 0;
            }
        } else {
            return false;
        }
        m++;
    }

    return true;
}

int main() {
    map <int, int> monsters;

    int t;
    cin >> t;

    int s;
    int n, k, arra[MAXLEN * 3], arrb[MAXLEN * 3];
    while (t--) {
        monsters.clear();

        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> arra[i];
        }

        s = 1;
        for (int i = 0; i < n; i++) {
            cin >> arrb[i];
            
            if (arrb[i] > s) s = arrb[i];
        }

        for (int i = 0; i < n; i++) {
            monsters[abs(arrb[i])] += arra[i];
        }

        // for (auto i = monsters.begin(); i != monsters.end(); i++) {
        //     cout << i->first << ' ' << i->second << '\n';
        // }
        // cout << '\n';

        cout << (solve(s, k, monsters) ? "YES" : "NO") << '\n';

    }

    return 0;
}