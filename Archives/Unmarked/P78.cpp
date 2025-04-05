#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    unordered_map <string, int> freq;

    int n;
    cin >> n;

    string x;
    while (n--) {
        cin >> x;

        if (freq[x] == 0) {
            cout << "OK" << '\n';
        } else {
            cout << x << freq[x] << '\n';
        }

        freq[x]++;
    }

    return 0;
}