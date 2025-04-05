#include <bits/stdc++.h>

#define MAXLEN 20

using namespace std;

int main()
{
    long long n;
    int arr[MAXLEN];

    cin >> n;

    int m = floor(log10(n) + 1);

    int d = 0, f = 0;
    for (int i = 0; i < m; i++) {
        d = (int)(n / pow(10, m-i-1)) % 10;
        cout << ( f != 0 || d != 9 ? f = 1, ( d >= 5 ? 9 - d : d ) : 9 );
    }
    cout << '\n';
}