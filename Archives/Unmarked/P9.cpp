#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, k;
    while (t--) {
        cin >> n >> k;
        cout << k + (int)ceil((double)k/(n-1)) - 1 << '\n';
    }

}