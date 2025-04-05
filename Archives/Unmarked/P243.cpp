#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int n, arr[MAXLEN * 3];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        sort(arr, arr+n);

        cout << abs(arr[0] - arr[n-1]) + abs(arr[n-1] - arr[1]) + abs(arr[1] - arr[n-2]) + abs(arr[n-2] - arr[0]) << '\n';
    }

    return 0;
}