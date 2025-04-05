#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int sumofdigits(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    int n, arr[MAXLEN * 3];

    int sum = 0;
    for (int i = 1; i <= 200000; i++) {
        sum += sumofdigits(i);
        arr[i] = sum;
    }

    while (t--) {
        cin >> n;

        cout << arr[n] << '\n';
    }

    return 0;
}