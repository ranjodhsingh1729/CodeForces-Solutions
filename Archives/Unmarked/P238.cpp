#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    unordered_map <int, int> freq;
    int t;
    cin >> t;

    int n, arr[MAXLEN * 2];
    while (t--) {
        freq.clear();

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        ll points = 0;
        for (auto i = freq.begin(); i != freq.end(); i++) {
            if (i->second > 1) {
                points += i->second - 1;
            }
        }
        
        cout << points << '\n';
    }

    return 0;
}