#include <bits/stdc++.h>
 
#define MAXLEN 100000
 
using namespace std;
 
int less_and_equal(int x, int n, int arr[]) {
    int l = 0, h = n, p;
    while (h - l > 0) {
        p = (l+h)/2;
        if (x > arr[p]) {
            l = p+1;
        } else if (x < arr[p]) {
            h = p;
        } else {
            if (p + 1 == n) {
                return n;
            } else {
                if (x == arr[p+1]) {
                    l = p+1;
                } else {
                    return p+1;
                }
            }
        }
    }
    if (x == arr[l]) {
        return l+1;
    } else {
        return l;
    }
}
 
int main() {
    int n, m, arr_n[MAXLEN * 2], arr_m[MAXLEN * 2];
 
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr_n[i];
    }
 
    sort(arr_n, arr_n+n);
 
    for (int i = 0; i < m; i++) {
        cin >> arr_m[i];
    }
 
    for (int i = 0; i < m; i++) {
        cout << less_and_equal(arr_m[i], n, arr_n) << ' ';
    }
 
    cout << '\n';
 
    return 0;
}