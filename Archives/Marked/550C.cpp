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


string inttostr(int x) {
    string y;
    if (!x) {
        y = "0";
        return y;
    }

    while (x) {
        y += x%10 + '0'; x /= 10;
    }
    string z;
    for (int i = y.size()-1; i >= 0; i--) {
        z += y[i];
    }
    return z;
}

void solve() {
    string x;
    cin >> x;
    int n = x.size();

    bool f = 0;
    int i, j, k;
    for (i = 0; i <= 1000; i+=8) {
        string a = inttostr(i);
        for (j = 0, k = 0; j < n && k < a.size(); j++) {
            if (x[j] == a[k])
                k++;
        }
        if (k >= a.size()) {
            f = 1;
            break;
        }
    }

    if (f) {
        cout << "YES" << '\n';
        cout << i << '\n';
    } else {
        cout << "NO" << '\n';
    }
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