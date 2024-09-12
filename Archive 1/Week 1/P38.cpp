#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, flag;
    string a, b, x;
    while (t--) {
        cin >> n;
        cin >> x;

        flag = 0;
        a = b = "";
        for (int i = 0; i < n; i++) {
            if (x[i] == '0') {
                a += '0';
                b += '0';
            } else if (x[i] == '1') {
                if (flag) {
                    a += '0';
                    b += '1';
                } else {
                    a += '1';
                    b += '0';
                    flag = 1;
                }
            } else {
                if (flag) {
                    a += '0';
                    b += '2';
                } else {
                    a += '1';
                    b += '1';
                }
            }
        }

        cout << a << '\n';
        cout << b << '\n';
    }

}