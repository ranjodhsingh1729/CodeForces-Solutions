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

    int rt = sqrt(MAXLEN);
    int arr[MAXLEN+1] = { 0 };

    arr[1] = 1;
    for (int i = 2; i <= rt; i++) {
        if (!arr[i]) {
            for (int j = 2; i*j <= MAXLEN; j++) {
              arr[i*j] = 1;
            }
        }
    }

    int t;
    cin >> t;

    ll n, m, p, fv, ff;
    map <ll, int> freq;

    while (t--) {
        freq.clear();

        cin >> n;

        m = n;
        ff = 0;
        rt = sqrt(n);
        for (int i = 2; i <= rt; i++) {
            if (!arr[i]) {
                while (m % i == 0) {
                    m /= i;
                    freq[i]++;
                    if (freq[i] > ff) {
                        fv = i, ff = freq[i];
                    }
                }
            }
            if (m == 1) break;
        }
        if (ff < 2) {
            cout << 1 << '\n';
            cout << n << '\n'; continue;
        }

        cout << ff << '\n';
        for (int i = 0; i < ff-1; i++) {
            cout << fv << ' ';
        }
        cout << n / (ll) (pow(fv, ff-1)) << '\n';
    }

    return 0;
}