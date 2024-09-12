#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;
 
void init_io() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}
 
int main() {
    map <ll, int> freq;
 
    init_io();
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
 
    ll s;
    int n, x, f;
    while (t--) {
        freq.clear();
 
        cin >> n;

        f = 0;
        s = 0;
        freq[s]++;
        for (int i = 0; i < n; i++) {
            cin >> x;
            s += i & 1 ? x : -x;
            freq[s]++;
            if (freq[s] > 1) f = 1;
        }
 
        if (f) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
 
    }
 
    return 0;
}