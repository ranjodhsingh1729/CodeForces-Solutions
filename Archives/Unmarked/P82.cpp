#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

void threefactors(int n) {
    int root = sqrt(n);
    int i, j, temp, flag = 0;
    for (i = 2; i <= root; i++) {
        for (j = i+1; j <= root; j++) {
            temp = n / (i * j);
            if ((i * j * temp) == n && (i != temp && j != temp)) {
                cout << "YES" << '\n' << i << ' ' << j << ' ' << temp << '\n'; return;
            }
        }
    }
    cout << "NO" << '\n'; return;
}

int main() {
    int t;
    cin >> t;

    int n, arr[3];
    while (t--) {
        cin >> n;

        threefactors(n);
    }

}