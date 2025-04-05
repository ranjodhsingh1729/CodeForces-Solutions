#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

string binary(ll x) {
    string y = "";

    while (x) {
        y = (char) ((x % 2) + '0') + y;
        x /= 2;
    }
    
    return y;
}

int main() {
    int t;
    cin >> t;

    int n, arr[MAXLEN * 3];
    while (t--) {
        cin >> n;

        string b = binary(n);

        int j, f = 0;
        ll total = 0;
        for (int i = b.length()-1; i >= 0; i--) {
            if (b[i] == '1') {
                j = b.length() - 1 - i;
                while (i >= 0) {
                    if (b[i] == '0') {
                        b[i] == '1';
                        f = 1;
                        break;
                    }
                    i--;
                }
                i++;
                if (f) {
                    f = 0;
                    total += pow(2, j);
                }
            }
        }
        
        cout << total << '\n';
    }

    return 0;
}