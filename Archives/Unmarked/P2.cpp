#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'y':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'Y':
            continue;
        }
        cout << '.' << ((s[i] >= 65 && s[i] <= 90)? (char)(s[i] + 32): s[i]);
    }
    cout << '\n';

}