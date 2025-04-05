#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int n, temp;
    map <int, int> freq;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        freq[temp]++;
    }

    auto l = freq.begin();
    auto r = freq.rbegin();

    cout << r->first - l->first << ' ' << ((r->first == l->first) ? ((long long) (r->second) * (long long) (r->second - 1)) / 2LL : ((long long) r->second * (long long) l->second)) << '\n';

    return 0;
}