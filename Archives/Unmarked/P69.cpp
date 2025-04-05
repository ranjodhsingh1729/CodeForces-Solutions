#include <bits/stdc++.h>

#define MAXLEN 100000

// #define probability(diff, fails) (((double) factorial(fails) / ((double) factorial((fails + diff) / 2) * (double) factorial((fails + diff) / 2 - diff))) / (double) pow(2, fails))

using namespace std;

int factorial(int x) {
    int f = 1;
    for (int i = 2; i <= x; i++) {
        f *= i;
    }
    return f;
}

double probability(int diff, int fails) {
    int x = (fails + diff) / 2;
    int y = (fails + diff) / 2 - diff;

    return (((double) factorial(fails) / ((double) factorial(x) * (double) factorial(y))) / (double) pow(2, fails));
}

int main() {
    cout << fixed;
    cout << setprecision(12);

    string orig, copy;
    cin >> orig >> copy;

    int x1 = 0, x2 = 0, fails = 0;
    for (int i = 0; i < orig.length(); i++) {
        if (orig[i] == '+')
            x1++;
        else
            x1--;

        if (copy[i] == '+') {
            x2++;
        } else if (copy[i] == '-') {
            x2--;
        } else {
            fails++;
        }
    }

    if (fails) {
        int diff = abs(x2 - x1);
        if (diff % 2 == fails % 2) {
            if (diff <= fails) {
                // cout << diff << ' ' << fails << '\n';
                cout << probability(diff, fails) << '\n';
            } else {
                cout << 0.0 << '\n';
            }
        } else {
            cout << 0.0 << '\n';
        }
    } else {
        if (x1 == x2) {
            cout << 1.0 << '\n';
        } else {
            cout << 0.0 << '\n';
        }
    }
}