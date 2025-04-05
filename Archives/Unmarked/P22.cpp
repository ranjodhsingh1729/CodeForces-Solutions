#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    unordered_map <int , int> freq;

    int t;
    cin >> t;

    long long count;
    long long n, arr[MAXLEN * 2];
    while (t--) {
        freq.clear();

        cin >> n;

        for (int i = 0; i < n; i++){
            cin >> arr[i];
            arr[i] -= i+1;
            freq[arr[i]]++;
        }

        count = 0;
        for (auto i = freq.begin(); i != freq.end(); i++) {
            count += (long long) (i->second) * (i->second - 1) / 2;
        }

        cout << count << '\n';
    }



}