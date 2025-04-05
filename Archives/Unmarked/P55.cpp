#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int no = -1;
int ne = -0;

int nxtodd() {
    no += 2;
    return no;
}

int nxteve() {
    ne += 2;
    return ne;
}

int main() {
    int t;
    cin >> t;

    int n, k;
    while (t--) {
        no = -1, ne = 0;
        cin >> n >> k;

        int q = n / (k + 1);
        int r = n % (k + 1);

        int i;
        for (i = 1; i <= k+1; i++) {
            for (int j = 0; j < (i != k ? q : q+r); j++) {
                cout << (i % 2 ? nxtodd() : nxteve()) << ' '; 
            }
        }

        cout << '\n';
    }

}