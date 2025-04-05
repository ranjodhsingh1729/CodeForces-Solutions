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


int greaterthanequalto(int x, int l, int h, int n, int arr[]) {
    int p;
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

    int n, arr[MAXLEN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    int cnt = 1;
    int cur, tmp;
    cur = arr[0];
    for (int i = 1; i < n; i++) {
        tmp = greaterthanequalto(cur, i, n, n, arr);
        if (tmp != n) {
            cur += arr[tmp];
            cnt++;
        } else {
            break;
        }
    }

    cout << cnt << '\n';
    
    return 0;
}