#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void fileio() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

void solve() {
    int n;
    string x;
    cin >> x;
    n = x.size();

    map <int, int> index;

    int ac = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == '+') {
            ac++;
        } else {
            ac--;
        }

        if (ac < 0 && !index[-ac]) {
            index[-ac] = i+1;
        }
    }

    ll sum = 0;
    for (auto itr = index.begin(); itr != index.end(); itr++) {
        sum += itr->second;
    }

    cout << n+sum << '\n';
}


int main() {
    FIXIO;
    //fileio();

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}