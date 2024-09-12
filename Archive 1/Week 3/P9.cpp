#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int maxi, man, score;
    int runs[22], wickets[22];
    while (t--) {
        for (int i = 0; i < 22; i++) {
            cin >> runs[i];
            cin >> wickets[i];
        }

        maxi = 0;
        for (int i = 0; i < 22; i++) {
            score = runs[i] + 20 * wickets[i];
            if (score > maxi) maxi = score, man = i;
        }

        cout << man+1 << '\n';
    }

    return 0;
}