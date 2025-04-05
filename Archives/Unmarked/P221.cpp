#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int n, arr[MAXLEN * 2];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr+n);

        int best = 0, curr;
        for (int i = 0; i < n; i++) {
            curr = arr[n-i-1]*(i+1);
            best = max(best, curr);
        }

        cout << best << '\n';
    }

    return 0;
}