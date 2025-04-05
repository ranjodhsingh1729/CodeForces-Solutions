#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;

    bool flag = true;
    int root = sqrt(x);
    for (int i = 2; i <= root; i++) {
        if (x % i == 0) {
            flag = false; break;
        }
    }

    return flag;
}

int main() {
    int n;
    int arr[MAXLEN];
    int temp, root, factors;


    cin >> n;

    arr[0] = 1;
    factors = 1, root = sqrt(n);
    for (int i = 2; i <= root; i++) {
        if (n % i == 0) arr[factors++] = i;
    }
    temp = factors;
    for (int i = 0; i < temp; i++) {
        arr[factors++] = n / arr[temp - i - 1];
    }

    for (int i = 0; i < factors; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';


    return 0;
}