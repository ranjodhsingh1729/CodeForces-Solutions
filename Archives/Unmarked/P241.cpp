#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;


ll sum_matrix(int a, ll n, int arr[500][500]) {
    for (int i = 0; i < n/pow(2,a); i++) {
        for (int j = 0; j < n; j++) {
            if (a % 2 == 0) {
                arr[i][j] = j+1;
            } else {
                arr[j][i] = j+1;
            }
        }
    }
}

ll print_matrix(int a, ll n) {
    for (int i = 0; i < n/pow(2,a); i++) {
        if (a % 2 == 0) {
            cout << 1 << ' ' << i+1 << ' ';
        } else {
            cout << 2 << ' ' << i+1 << ' ';
        }

        for (int j = 0; j < n; j++) {
            cout << j+1 << ' ';
        }

        cout << '\n';
    }
}


int main() {
    int t;
    cin >> t;

    ll sum;
    int n, arr[500][500];
    while (t--) {
        cin >> n;

        for (int i = 0; i < 500; i++) {
            for (int j = 0; j < 500; j++) {
                arr[i][j] = 0;
            }
        }

        for (int i = 0; n/pow(2, i) != 0; i++) {
            sum_matrix(i, n, arr);
        }

        sum = 0;
        for (int i = 0; i < 500; i++) {
            for (int j = 0; j < 500; j++) {
                sum += arr[i][j];
            }
        }

        for (int i = 0; n/pow(2, i) != 0; i++) {
            print_matrix(i, n);
        }

        cout << sum << '\n';

    }

    return 0;
}