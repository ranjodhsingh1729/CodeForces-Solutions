#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int binary_search_modification_1(int x, int n, int arr[], map <int, int> freq) {
    int l = 0, h = n, p;
    while (h - l > 0) {
        p = (l+h)/2;
        if (x > arr[p]) {
            l = p+1;
        } else if (x < arr[p]) {
            h = p;
        } else {
            return p;
        }
    }
    return l;
}

int main() {
    int t;
    cin >> t;

    int a, b;
    while (t--) {
        cin >> a >> b;

        if (a % 2 == 0 && a / 2 != b || b % 2 == 0 && b / 2 != a) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }

    return 0;
}