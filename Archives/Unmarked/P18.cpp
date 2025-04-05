#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, arr[MAXLEN * 2], count;
    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] - arr[i] == j - i) count++;
            }
        }
        
        cout << count << '\n';
    }



}