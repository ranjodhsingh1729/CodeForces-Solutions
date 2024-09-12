#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    int n;
    string p;
    while (t--) {
        cin >> n >> p;

        int count = 0;
        int thorns = 0;
        for (int i = 1; thorns < 2 && i < p.length(); i++) {
            if (p[i] == '*') {
                thorns++;
            } else {
                thorns = 0;
                if (p[i] == '@') {
                    count++;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}