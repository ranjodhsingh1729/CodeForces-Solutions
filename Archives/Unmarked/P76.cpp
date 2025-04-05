#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main(void) {
    int n, arr[MAXLEN / 100];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int count_even = 0, count_odd = 0;
    for (int i = 0; i < 3; i++) {
        (arr[i] % 2) ? count_odd++ : count_even++;
    }

    bool odd = (count_odd > count_even ? true : false);

    int i;
    for (i = 0; i < n; i++) {
        if (odd ? (arr[i] % 2 == 0) : (arr[i] % 2 == 1)) {
            break;
        }
    }

    cout << i+1 << '\n';

    return 0;
}