#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll MOD = 1e9+7;
const int MAXN = 1e6+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll k;
    cin >> k;
    vector <int> amazing;

    int x = k;
    while (x) {
        int i = 2;
        while (i*(i-1)/2 <= x)
            i++;
        amazing.push_back(i-1);
        x -= (i-1)*(i-2)/2;
    }


    int sum = 0;
    for (auto &i: amazing) {
        sum += i;
    }
    cout << sum << '\n';

    int prv = amazing.size();
    for (int i = 0; i < amazing.size(); i++) {
        for (int j = prv; j < prv+amazing[i]; j++) {
            cout << i << ' ' << j << '\n';
        }
        prv = prv+amazing[i];
    }
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}