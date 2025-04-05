#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int n, arr_n[MAXLEN];
    int m, arr_m[MAXLEN];
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr_n[i];
        
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> arr_m[i];

    
    for (int i = 1; i < n; i++)
        arr_n[i] += arr_n[i-1];

    int l, h, p;
    for (int i = 0; i < m; i++) {
        l = 0, h = n;
        while (h - l > 0) {
            p = (h + l) / 2;
            if (arr_m[i] > arr_n[p]) {
                l = p + 1; 
            } else if (arr_m[i] < arr_n[p]) {
                h = p;
            } else {
                break;
            }
        }
        cout << (h + l) / 2 + 1  << '\n';
    }
}