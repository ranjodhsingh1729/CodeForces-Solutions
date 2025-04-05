#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;


int main() {
    double b, d, e;
    int n, l, arr[MAXLEN / 100];
    cin >> n >> l;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    d = 0;
    for (int i = 0; i < n-1; i++)
        if ((arr[i+1] - arr[i]) > d) d = (arr[i+1] - arr[i]);
    d /= 2;

    b = arr[0], e = l-arr[n-1];

    cout << fixed;
    cout << ((b - d > 1e-9) ? (b - e > 1e-9 ? b : e) : (d - e > 1e-9 ? d : e)) << '\n';
}