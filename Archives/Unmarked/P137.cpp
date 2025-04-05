#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;
    int count;
    int n, x, y, arr[MAXLEN * 3];
    while (t--) {
        cin >> n >> x >> y;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (((arr[i] + arr[j]) % x == 0) && (abs(arr[i] - arr[j]) % y == 0)) {
                    count++;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}