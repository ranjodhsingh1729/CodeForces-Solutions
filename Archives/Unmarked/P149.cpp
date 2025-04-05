#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, sum, arr[MAXLEN];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr+n);

        sum = 0;
        for (int i = 1; i < n; i++) {
            sum += arr[i] - arr[i-1];
        }
        
        cout << sum << '\n';
    }

    return 0;
}