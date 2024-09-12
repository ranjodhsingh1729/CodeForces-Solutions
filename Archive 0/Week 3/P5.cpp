#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int a, b;
    string x;
    while (t--) {
        cin >> x;

        a = b = 0;
        for (int i = 0; i < x.length(); i++) {
            if (x[i] == 'A')
                a++;
            else
                b++;
        }

        cout << (a > b ? 'A' : 'B') << '\n';
        
    }

    return 0;
}