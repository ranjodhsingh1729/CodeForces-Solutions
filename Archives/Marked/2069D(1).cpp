#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pre(r, l) for (ll i = (r); i >= ll((l)); i--)
#define fro(l, r) for (ll i = (l); i <= ll((r)); i++)


bool check(int k, int n, string x) {
    vector<int> A(256), B(256);
    int i = 0;
    for (i = 0; i < k; i++) {
        A[int(x[i])]++;
        B[int(x[n-i-1])]++;
    }
    while (i < n/2) {
        if (x[i] != x[n-i-1])
            return false;
        i++;
    }
    for (i = 0; i < 256; i++) {
        if (A[i] || B[i]) {
            cout << A[i] << ':' << B[i] << '\n';
        }
        if (A[i] < B[i]) {
            cout << (char)i << '\n';
            return false;
        }
    }
    return true;
}

void solve() {
    string x;
    cin >> x;
    int n = x.size();

    int a = 0;
    while (a < n/2 && x[a] == x[n-a-1]) a++;

    if (a == n/2) {
        cout << 0 << '\n';
        return;
    }

    x = x.substr(a, n-a-a);
    n = x.size();

    cout << x << '\n';
    for (int i = 0; i <= n; i++) {
        cout << check(i, n, x) << ' ';
    }
    cout << '\n';


    int l = 0, r = n+1, p;
    while (l < r) {
        p = (l+r)/2;
        if (check(p, n, x)) {
            r = p;
        } else {
            l = p+1;
        }
    }


    cout << l << '\n';
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