#include <bits/stdc++.h>
 
#define MAXLEN 100000
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    int n, x, sum, neve, nodd, arr[MAXLEN * 3];
    while (t--) {
        cin >> n >> x;
 
        sum = 0, neve = 0, nodd = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            if (arr[i] % 2) {
                nodd++;
            } else {
                neve++;
            }
        }

        if (nodd == 0) {cout << "NO" << '\n'; continue;}
 
        if ((x - ((min(x, nodd) % 2) ? min(x, nodd) : (min(x, nodd) - 1))) <= neve) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
 
}
