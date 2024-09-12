#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    long long max_pair = (n-m)*(n-m+1)/2;

    long long min_pair = ((n/m+1)*(n/m)/2)*(n%m) + ((n/m)*(n/m-1)/2)*(m-n%m);

    cout << min_pair << ' ' << max_pair << '\n';

    return 0;
}