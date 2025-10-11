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
    /*
        Every Column has two associated numbers
        number of changes to paint white and no of changes to paint black
        lets say w for the former and b for the later

        No we have two parallel arrays of numbers
        we need to chose one from each index and minimize the sum
        under the constraint that consecutive groups have width bw x and y;

        We know this is going the DP way isn't it.

        state: minimum sum so far given the current col is painted black
               and minimum sum so far given the current col is painted white

        limitation: how to encode validity?

        Reason Greedy Won't Work:
        thinking on a lower level tells us that there can be columns which
        can be extreemly cheap to paint one way and extreemely expensive to 
        paint the other way now an optimal solution will choose cheap one
        unless it interferes with a more diffrence making choice or multiples
        such that their combined difference outweigh local benefit.

        so the whole array of cols is divided into groups
        each group being white or black. first one can be white or it can be black
        we save the cost for each and boundary and then decide what the next group
        should be but there is a leeway in the boundary how to deal with that.

        Simple Sol: Look Back from y to x and transition.



        a1, a2, a3, a4, a5, a6
        b1, b2, b3, b4, b5, b6
    */

    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<pair<ll,ll>> A(m);

    char temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            if (temp == '.')
                A[j].first++;
            else
                A[j].second++;
        }
    }

    vector<pair<ll,ll>> dp(m);
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        for (int j = i; j >= 0 && j > i - x; j--) {
            a += A[j].first;
            b += A[j].second;
        }
        
        if (i - x >= 0) {
            dp[i].first = a + dp[i - x].second;
            dp[i].second = b + dp[i - x].first;
        } else if (i - x == -1) {
            dp[i].first = a;
            dp[i].second = b;
        } else {
            dp[i].first = dp[i].second = INT_MAX;
        }
        
        for (int j = i - x; j >= 0 && j > i - y; j--) {
            a += A[j].first;
            b += A[j].second;
            dp[i].first = min(dp[i].first, a + (j - 1 >= 0 ? dp[j - 1].second : 0));
            dp[i].second = min(dp[i].second, b + (j - 1 >= 0 ? dp[j - 1].first : 0));
        }
    }

    cout << min(dp[m-1].first, dp[m-1].second) << '\n';
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