#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;


int main() {
    unordered_map <char, int> freq;

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        freq[s[i]]++;
    }

    int count = 0;
    for (auto i = freq.begin(); i != freq.end(); i++) {
        if (i->second % 2) count++;
    }

    // if (count <= 1) {
    //     cout << "First" << '\n';
    // } else {
    //     if (count % 2) {
    //         cout << "First" << '\n';
    //     } else {
    //         cout << "Second" << '\n';
    //     }
    // }

    if (count <= 1) {
        cout << "First" << '\n';
    } else {
        if (s.length() % 2) {
            cout << "First" << '\n';
        } else {
            cout << "Second" << '\n';
        }
    }

    return 0;
}