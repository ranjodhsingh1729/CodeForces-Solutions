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
    map <int, int> freq;
    vector <int> via(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> via[i];
        freq[via[i]]++;
    }

    int f, mx, cur;
    f = mx = cur = 0;
    int a, b, ca, cb;
    for (int i = 0; i < n; i++) {
        if (f) {
            if (freq[via[i]] == 1) {
                cur++;
            } else {
                f = 0;
                cb = i;
                if (mx < cur) {
                    mx = cur;
                    a = ca, b = cb;
                }
            }
        } else {
            if (freq[via[i]] == 1) {
                ca = i;
                f = cur = 1;
            } else {
                //
            }
        }
    }
    if (f) {
        if (mx < cur) {
            mx = cur;
            a = ca, b = n;
        }
    }


    if (mx) {
        cout << a+1 << ' ' << b << '\n';
    } else {
        cout << 0 << '\n';
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