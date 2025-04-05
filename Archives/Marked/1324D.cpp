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
    ll n, temp;
    cin >> n;
    vector <int> via(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> via[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> temp;
        via[i] -= temp;
    }
    sort(via.begin(), via.end());


    ll sum = 0;
    for (int i = 0; i < n; i++) {
        temp = upper_bound(via.begin()+i+1, via.end(), -via[i]) - (via.begin()+i+1);
        sum += n-(i+1) - temp;
    }

    cout << sum << '\n';
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}