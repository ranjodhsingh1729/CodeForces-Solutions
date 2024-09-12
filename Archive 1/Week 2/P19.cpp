#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

bool is_sorted(int n, int arr[]) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    int temp;
    int n, arr[MAXLEN * 3];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        
        if (n > 3) {
            cout << "YES" << '\n';
        } else if (n == 3) {
            if (is_sorted(n, arr)) {
                cout << "YES" << '\n';
            } else {
                temp = arr[2];
                arr[2] = arr[0];
                arr[0] = temp;

                if (is_sorted(n, arr)) {
                    cout << "YES" << '\n';
                } else {
                    cout << "NO" << '\n';
                }
            }

        } else {
            if (is_sorted(n, arr)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}