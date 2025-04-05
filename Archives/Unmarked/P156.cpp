#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, sum, arr[MAXLEN];
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2*n; i++)
            cin >> arr[i];
        
        sort(arr, arr+(2*n));

        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[2*i];
        }
        
        cout << sum << '\n';
    }

    return 0;
}