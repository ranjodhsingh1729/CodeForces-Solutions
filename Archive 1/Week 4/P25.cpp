#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int k, q, krr[MAXLEN], qrr[MAXLEN];
    while (t--) {
        cin >> k >> q;
        for (int i = 0; i < k; i++) {
            cin >> krr[i];
        }
        for (int j = 0; j < q; j++) {
            cin >> qrr[j];
        }

        for (int i = 0; i < q; i++) {
            if (qrr[i] < krr[0]) {
                cout << qrr[i] << ' ';
            } else {
                cout << krr[0] - 1 << ' ';
            }
        }
        cout << '\n';

    }

    return 0;
}