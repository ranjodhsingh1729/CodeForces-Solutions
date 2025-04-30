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
    ll n, c;
    cin >> n >> c;
    vector<ll> arr(n);
    for (auto &x: arr)
        cin >> x;
        
    auto check = [&](ll mid) -> int {
        mid *= 2;
        ll sum = 0, tmp;
        for (auto &i: arr) {
            tmp = powl(i+mid, 2);
            if (LLONG_MAX - tmp < sum) {
                return 1;
            }
            sum += tmp;
        }

        if (sum == c) {
            return 0;
        } else if (sum > c) {
            return 1;
        } else {
            return -1;
        }
    };
    
    ll l = 1, r = 1e14, mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        int flag = check(mid);

        if (flag < 0) {
            l = mid + 1;
        } else if (flag > 0) {
            r = mid;
        } else {
            break;
        }
    }

    cout << mid << '\n';
}


int main() {
    FIXIO;

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}