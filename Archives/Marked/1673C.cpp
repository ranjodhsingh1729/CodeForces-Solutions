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


void solve(vector<int> &dp) {
    ll n;
    cin >> n;

    /*
    // Can use each integer more than once.
    // No of ways to reach n using integers in basis (unique / order doesn't matter)

    YOU FORGOT - **AGAIN** ---  WHY :( :/
    */

    cout <<  dp[n] << '\n';
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    cin >> t;

    auto check = [&](int val) {
        string x = to_string(val);
        string y = x;
        reverse(y.begin(), y.end());

        return x == y;
    };

    vector<int> basis;
    for (int i = 1; i <= 4e4; i++) {
        if (check(i))
            basis.push_back(i);
    }


    vector<int> dp(4e4+1, 0);
    dp[0] = 1;
    for (auto &i: basis) {
        for (int j = i; j <= 4e4; j++) {
            dp[j] = mod(dp[j] + dp[j-i], 1e9+7);
        }
    }


    while (t--) {
        solve(dp);
    }

    return 0;
}