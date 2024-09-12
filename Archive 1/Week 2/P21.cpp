#include <bits/stdc++.h>

#define MAXLEN 105000

typedef long long ll;

using namespace std;

void sieve_of_eratosthenes(ll n, bool arr[]) {
    memset(arr, true, n);

    for (ll i = 2; i < n; i++) {
        if (arr[i]) {
            for (ll j = i * i; j < n; j += i) {
                arr[j] = false;
            }
        }
    }
}


int main() {
    int t;
    cin >> t;

    int n;
    bool arr[MAXLEN];
    sieve_of_eratosthenes(MAXLEN, arr);
    while (t--) {
        cin >> n;

        int c = 0;
        if (n & 1) {
            cout << 1 << ' ';
            for (int i = 2; c < n/2 && i < MAXLEN; i++) {
                if (arr[i]) {
                    c++;
                    cout << i << ' ' << i << ' ';
                }
            }
        } else {
            for (int i = 2; c < n/2 && i < MAXLEN; i++) {
                if (arr[i]) {
                    c++;
                    cout << i << ' ' << i << ' ';
                }
            }
        }

        cout << '\n';

    }

    return 0;
}