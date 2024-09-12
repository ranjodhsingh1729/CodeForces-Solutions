#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    string x, y;
    while (t--) {
        cin >> x >> y;

        int f = 0; 
        int n = x.length();
        
        char temp;
        for (int i = 0; i < n; i++) {
            if (f) {
                if (f == 1 ? x[i] > y[i] : y[i] > x[i]) {
                    temp = x[i];
                    x[i] = y[i];
                    y[i] = temp;
                }
            } else {
                if (x[i] != y[i]) {
                    f = x[i] > y[i] ? 1 : 2;
                }
            }
        }

        cout << x << '\n' << y << '\n';   
    }

    return 0;
}