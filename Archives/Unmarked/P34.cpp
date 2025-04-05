#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    string c;
    int p = 1, q = 1000000, r;

    while (q - p > 1) {
        r  = (p+q)/2;
        cout << r << endl;

        cin >> c;

        if (c == "<") {
            q = r - 1;
        } else if (c == ">=") {
            p = r;
        } else {
            cout << "ERROR" << endl;
            return 0;
        }
    }

    cout << q << endl;
    cin >> c;

    if (c == "<") {
        cout << "! " << p << endl;
    } else {
        cout << "! " << q << endl;
    }

}