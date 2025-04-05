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
    map <char, int> mp;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    init_io();

    ll t;
    cin >> t;

    int k;
    int n;
    string x;
    while (t--) {
        mp.clear();
        cin >> x;
        
        k = 0, n = x.size();
        for (int i = 0; i < n; i++) {
            mp[x[i]]++;
            if (mp[x[i]] == 2) {
                k += mp.size()-1;
                mp.clear();
            }
        }

        k += mp.size();

        cout << k << '\n';


    }

    return 0;
}