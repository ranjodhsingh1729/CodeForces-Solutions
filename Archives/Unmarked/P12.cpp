#include <bits/stdc++.h>

#define MAXLEN 20

using namespace std;

int main() {
    long long n;
    int arr[MAXLEN];

    cin >> n;

    int a;
    for (a = 0; n; a++) {
        arr[a] = n % 10;
        n /= 10;
    }

    if (arr[a-1] == 9) {
        cout << 9;
    } else {
        cout << (arr[a-1] >= 5 ? 9 - arr[a-1]: arr[a-1]);
    }

    for (int i = a - 2; i >= 0; i--) {
        cout << (arr[i] >= 5 ? 9 - arr[i]: arr[i]);
    }
    
    cout << '\n';
    
}