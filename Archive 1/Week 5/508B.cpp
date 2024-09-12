#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

void init_io() {
    #ifndef ONLINE_JUDGE
    freopen("streams/input.txt", "r", stdin);
    freopen("streams/output.txt", "w", stdout);
    #endif
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init_io();

    string x;
    cin >> x;

    int n = x.length();

    int a, b;
    a = b = -1;
    for (int i = 0; i < n-1;  i++) {
        if ((x[i] & 1) == 0) {
            if (a == -1 && x[i] < x[n-1]) {
                a = i;
            } else {
                b = i;
            }
        }
    }

    int ind, tmp;
    if (a != -1 || b != -1) {
        ind = a != -1 ? a : b;

        tmp = x[ind];
        x[ind] = x[n-1];
        x[n-1] = tmp;

        cout << x << '\n';
    } else {
        cout << -1 << '\n';
    }



    return 0;
}