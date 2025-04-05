#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

void init_io() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

int binarysearch(int x, int y, int n, int arr[]) {
    int l = 0, r = n, p;
    while (r - l) {
        p = (l + r) / 2;
        if (x > arr[p]) {
            l = p+1;
        } else if (y <= arr[p]) {
            r = p;
        } else {
            return p;
        }
    }
    return -1;
}


int main() {
    init_io();

    int t;
    cin >> t;

    int n, q, l, r, pos, arr[2*MAXLEN], k, brr[2*MAXLEN];
    while (t--) {
        cin >> n;
        cin >> arr[0];

        k = 0;
        for (int i = 1; i < n; i++) {
            cin >> arr[i];
            if (arr[i] != arr[i-1]) {
                brr[k++] = i-1;
            }
        }

        // for (int i = 0; i < k; i++) {
        //     cout << brr[i] << ' ';
        // }
        // cout << "\n\n";

        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> l >> r;
            pos = binarysearch(l-1, r-1, k, brr);
            if (pos == -1) {
                cout << -1 << ' ' << -1 << '\n';
            } else {
                cout << brr[pos]+1 << ' ' << brr[pos]+2 << '\n';
            }
        }
        
        cout << '\n';
    }

    return 0;
}