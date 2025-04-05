#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int x;
    int n, arr[MAXLEN * 3];
    while (t--) {
        cin >> n;

        x = 0;
        while (n) {
            if (n%2) {
                x++;
            }
            n /= 2;
        }

        cout << (x % 2 ? "ODD" : "EVEN") << '\n';
        
    }

    return 0;
}