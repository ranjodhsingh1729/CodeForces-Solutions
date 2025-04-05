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

ll nlessthan(ll x, ll n, ll arr[]) {
    ll p, l = 0, h = n;
    while (l != h) {
        p = (l + h) / 2;
        if (x < arr[p]) {
            h = p;
        } else if (x > arr[p]) {
            l = p + 1;
        } else {
            if (p == 0) {
                return p;
            } else {
                if (x == arr[p-1]) {
                    h = p;
                } else {
                    return p;
                }
            }
        }
    }

    return l; // l == h
}



int main() {
    init_io();

    ll t;
    cin >> t;

    ll x;
    ll n, arr[2*MAXLEN], k, brr[2*MAXLEN];
    while (t--) {
        cin >> n;

        x = k = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] < i+1) {
                brr[k++] = i+1;
                x += nlessthan(arr[i], k, brr);
            }
        }

        cout << x << '\n';
    }

    return 0;
}