#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    map <int, int> freq;

    int t;
    cin >> t;

    int n, arr[MAXLEN * 2];
    while (t--) {
        freq.clear();

        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n; i++) {
            cout << (char) ('a' + freq[arr[i]]);
            freq[arr[i]]++;
        }
        cout << '\n';
    }

    return 0;
}