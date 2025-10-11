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
    ll n, m;
    cin >> n >> m;

    /*
        After reading the problem: one thing should be obvious 
        we can achive all values between n (root is 1) and n*(n+1)/2 (decreasing chain)

        Therefore goal is to achive intermediate values by shifting values
        before 1 to after 1 in a descending initial chain with value n*(n+1)/2

        what shifting a does: value += -(a - 1)

        lets say target n*(n+1)/2 - m = d;
        x lies between 0 and n*(n-1)/2;

        hypothesis 1: x can be expressed as n*(n+1)/2 - i/2(i+1) + y;
        where i lies between 0 and n and y is less than equal to i;

        n, 2n-1, 3n-2, 4n-3, ...

        d = -(x - k)
        where k is no of elements shifted.

        ---Step Back---

        eg: 6, 15

        6 5 4 3 2 1 : 21
        5 4 3 1 2 6 : 15
        6 5 1 2 3 4 : 15
        1 2 3 4 5 6 : 6
        2 1 2 3 4 5 : 7

        ------|----
        Sum_1  Sum_2

        sum of x <= n terms + count of remaining

        so reach sum m - (n - no of terms used) using terms from set [1, n] integers

        Would a brute loop work?
        
        ---- YOU IDIOT IT WORKS --- 

        Complexity of loop was always n
        Its Greedy and it works Proof?

        Intuition:
        Well we know ans is within reach
        We go from larger numbers first and you always have a number which can fit the decrease
        you require since you are trying larger numbers first you will not run out of numbers
        before reaching target decrease you need.
    */

    if (!(n <= m && m <= n*(n+1)/2)) {
        cout << -1 << endl;
        return;
    }

    ll d = n*(n+1)/2 - m;

    queue<int> q;
    for (int i = n; i >= 1; i--)
        q.push(i);

    vector<int> ans;
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (d && d >= cur - 1) {
            d -= cur - 1;
            q.push(cur);
        } else {
            ans.push_back(cur);
        }
    }

    cout << ans[0] << '\n';
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << ' ' << ans[i+1] << '\n';
    }
    cout << endl;
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