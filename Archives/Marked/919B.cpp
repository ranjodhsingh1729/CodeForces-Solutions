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


int sumofdig(int x) {
    int ans = 0;
    while(x) {
        ans += x%10;
        x /= 10;
    }
    return ans;
}


void solve() {
    int x;
    cin >> x;
    int k = 0;
    int i = 0;
    while (k < 10000) {
        if (sumofdig(i) == 10) {
            k++;
            if (k == x) {
                cout << i << '\n';
                return;
            }
        }
        i++;
    }
}


int main() {
    FIXIO;

    ll t;
    t = 1;

    while (t--) {
        solve();
    }

    return 0;
}