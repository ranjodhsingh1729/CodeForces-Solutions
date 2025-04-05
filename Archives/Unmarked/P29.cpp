#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    long long sum;
    int best, sign;
    int n, arr[MAXLEN * 2];
    while (t--) {
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sum = 0;
        int i = 0;
        while (i < n) {
            best = arr[i];
            sign = (arr[i] > 0 ? 1 : 0);
            while (i < n && (sign ? arr[i] > 0 : arr[i] < 0)) {
                if (arr[i] > best) best = arr[i];
                i++;
            }
            sum += best;
        }

        cout << sum << '\n';
    }
}