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


int ngreaterthanequalto(int x, int y, int l, int h, int n, int arr[]) {
    int p;
    while (l != h) {
        p = (l + h) / 2;
        if (x < arr[p]+y) {
            h = p;
        } else if (x > arr[p]+y) {
            l = p + 1;
        } else {
            if (p == 0) {
                return n-p;
            } else {
                if (x == arr[p-1]+y) {
                    h = p;
                } else {
                    return n-p;
                }
            }
        }
    }

    return n-l; // l == h
}

int nlessthanequalto(int x, int y, int l, int h, int n, int arr[]) {
    int p;
    while (l != h) {
        p = (l + h) / 2;
        if (x < arr[p]+y) {
            h = p;
        } else if (x > arr[p]+y) {
            l = p + 1;
        } else {
            if (p == n-1) {
                return p+1;
            } else {
                if (x == arr[p+1]+y) {
                    l = p+1;
                } else {
                    return p+1;
                }
            }
        }
    }

    return h; // l == h
}


int main() {
    init_io();

    int t;
    cin >> t;

    int n, l, r, arr[2*MAXLEN];
    while (t--) {
        cin >> n >> l >> r;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr+n);

        int a, b;
        ll total = 0;
        for (int i = 0; i < n; i++) {
            a = ngreaterthanequalto(l, arr[i], i+1, n, n, arr);
            b = nlessthanequalto(r, arr[i], i+1, n, n, arr);
            total += n < (a+b) ? (a+b) - n : 0;
        }

        cout << total << '\n';
    }

    return 0;
}
