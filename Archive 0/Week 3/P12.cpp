#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int n, arr[MAXLEN];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int l = -1;
        for (int i = 0; i < n ;i++) {
            if (arr[i] == 1) {
                l = i;
                break;
            }
        }

        int j, count = 0;
        for (int i = n - 1; i > l; i--) {
            if (arr[i] == 1) {
                for (j = i-1; j > l; j--) {
                    if (arr[j] == 0) {
                        break;
                    }
                }
                if (j > l) {
                    count++;
                    arr[i] = 0; arr[j] = 1;
                } else {
                    break;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}