#include <bits/stdc++.h>

#define MAXLEN 1000000

using namespace std;

typedef long long ll;

int main() {
    unordered_map <int, int> freq;

    int t;
    cin >> t;

    int l, a, b;
    int temp, xm, ym;
    while (t--) {
        freq.clear();

        cin >> a >> b >> l;

        xm = 0, temp = l;
        while (1) {
            if (temp % a == 0) {
                xm++;
                temp /= a;
            } else {
                break;
            }
        }

        ym = 0, temp = l;
        while (1) {
            if (temp % b == 0) {
                ym++;
                temp /= b;
            } else {
                break;
            }
        }

        int k = 0;
        for (int i = 0; i <= xm; i++) {
            for (int j = 0; j <= ym; j++) {
                temp = pow(a, i)*pow(b, j);
                if (l % temp == 0) {
                    if (freq[temp] == 0) {
                        k++;
                    }
                    freq[temp]++;
                }
            }
        }

        cout << k++ << '\n';
    }

    return 0;
}