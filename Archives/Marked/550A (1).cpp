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
    string x;
    cin >> x;
    int n = x.size();

    int a = 0, b = 0;
    for (int i = 0; !(a && b) && i < n-1; i++) {
        if (!b && x[i] == 'B' && x[i+1] == 'A') {
            b = 1;
            i++;
            continue;
        }
        if (b && !a && x[i] == 'A' && x[i+1] == 'B') {
            a = 1;
            i++;
        }
    }

    if (a && b) {
        cout << "YES" << '\n';
        return;
    }

    a = 0, b = 0;
    for (int i = 0; !(a && b) && i < n-1; i++) {
        if (a && !b && x[i] == 'B' && x[i+1] == 'A') {
            b = 1;
            i++;
            continue;
        }
        if (!a && x[i] == 'A' && x[i+1] == 'B') {
            a = 1;
            i++;
        }
    }

    cout << (a && b ? "YES" : "NO") << '\n';    
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