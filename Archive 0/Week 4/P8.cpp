#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int comp(int x, int n, char *a, char *b) {
    int i;
    for (i = x; i < n-1; i++) {
        if (*(a+i+1) != *(b+i)) {
            break;
        }
    }
    return *(a+i) - *(b+i);
}

int main() {
    int t;
    cin >> t;

    int c, k;
    ll n, x;
    char r1[2*MAXLEN], r2[2*MAXLEN], sp[2*MAXLEN+1];
    while (t--) {
        cin >> n;
        cin >> r1;
        cin >> r2;

        k = 0, x = 1;
        for (int i = 0; i < n-2; i++) {
            if (r1[i+1] == r2[i] && r1[i+1] <= r2[i+2])
                x++;
        }


        cout << x << '\n';
    }

    return 0;
}