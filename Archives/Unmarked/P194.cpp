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
        
        
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil(arr[i]/2.0);
        }

        cout << sum << '\n';
    }

    return 0;
}