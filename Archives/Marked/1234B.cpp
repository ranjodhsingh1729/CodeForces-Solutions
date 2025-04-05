#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n, k;
    cin >> n >> k;
    vector <int> via(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> via[i];
    }

    int p = 0, c = 0;
    vector <int> screen(k, 0);
    map <int, bool> onscreen;
    for (int i = 0; i < n; i++) {
        if (!onscreen[via[i]]) {
            if (c++ >= k) {
                onscreen[screen[p]] = 0;
            }
            screen[p] = via[i];
            p = mod(p+1, k);
            onscreen[via[i]] = 1;
        }
    }
    p = mod(p-1, k);

    cout << min(k, onscreen.size()) << '\n';
    for (int i = 0; i < min(k, onscreen.size()); i++) {
        cout << screen[p] << ' ';
        p = mod(p-1, k);
    }
    cout << '\n';

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