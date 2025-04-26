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


void solve() {
    ll n;
    cin >> n;
    string x;
    cin >> x;
    
    ll prev = 0, score = n;
    for (int i = 0; i < n; i++) {
        score += (prev^(x[i]-'0'));
        prev = x[i] - '0';
    }

    if (n == 1) {
        cout << score << '\n';
        return;
    }

    prev = 0;
    int no1s = 0, n10s = 0;
    for (int i = 0; i < n; i++) {
        if (prev == 0 && x[i]-'0' == 1) {
            no1s++;
        }
        if (prev == 1 && x[i]-'0' == 0) {
            n10s++;
        }

        prev = x[i]-'0';
    }

    if (no1s > 1 || n10s > 1) {
        cout << score - 2 << '\n';
        return;
    }

    if (max(0, no1s-1) != 0 || n10s != 0) {
        cout << score - 1 << '\n';
        return;
    }


    cout << score << '\n';
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