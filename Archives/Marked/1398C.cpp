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
    ll n;
    cin >> n;
    string x;
    cin >> x;
    vector <int> via(n+1, 0);
    for (int i = 1; i <= n; i++) {
        via[i] = x[i-1]-'0';
        via[i] += via[i-1];
    }

    map <int, int> freq;
    for (int i = 0; i <= n; i++) {
        via[i] -= i;
        freq[via[i]]++;
    }

    ll sum = 0;
    for (auto &x: freq) {   
        sum +=  (ll)x.second*((ll)x.second-1)/2;
    }
    cout << sum << '\n';
    

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