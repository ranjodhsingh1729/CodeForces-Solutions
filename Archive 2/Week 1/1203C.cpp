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

int hcf(int x, int y) {
    if (max(x, y) % min(x, y) == 0) {
        return min(x, y);
    } else {
        return hcf(min(x, y), max(x, y) % min(x, y));
    }
}

ll hcf_itr(ll x, ll y) {
    ll temp;
    if (x < y) {
        temp = x;
        x = y;
        y = temp;
    }

    while (temp = (x % y)) {
        x = y, y = temp;
    }

    return y;
}

int main() {
    init_io();

    ll n, arr[4*MAXLEN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll mf = arr[0];
    for (int i = 1; i < n; i++) {
        mf = hcf_itr(mf, arr[i]);
    }

    int nf = 0;
    int rt = (int) sqrt(mf);
    for (int i = 2; i <= rt; i++) {
        if (mf % i == 0) nf++;
    }

    nf *= 2;
    nf += 2;
    cout << nf-(floor(sqrt(mf)) == ceil(sqrt(mf))) << '\n';
        
    return 0;
}