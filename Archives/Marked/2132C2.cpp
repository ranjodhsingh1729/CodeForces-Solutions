#include <bits/stdc++.h>
#include <numeric>

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
    int n, k;
    cin >> n >> k;
    
    // number: 3**x => cost: 3**(x+1) + x * 3**(x-1)
    // where x is the no of watermelons being bought
    // You can buy 1, 3, 9, ... watermelons

    // 1: 3, 3: 10, 9: 33, 27: 108
    // next_number = 3 * prev_number
    // next_cost = 3 * prev_cost + prev_number
    
    // cost per mellon in deals (3 + x / 3)
    // 0: deal A: 3
    // 1: deal B: 3.33
    // 2: deal C: 3.66
    // 3: deal D: 4.0

    // minimum no of deals
    // sum of digits in base 3 numeric representation of requirement

    // minimum cost
    // just 3 * no of watermelons required

    // minimize under restrictions
    // start from base 3 representation and continuously shift to lower deals
    // try to shift larger deals first.

    int temp = n;
    vector<ll> baseRep;
    while (temp) {
        baseRep.push_back(temp % 3);
        temp /= 3;
    }

    int minDeals = accumulate(baseRep.begin(), baseRep.end(), 0LL);

    if (minDeals > k) {
        cout << -1 << '\n';
        return;
    }

    // Will definately TLE
    // int curDeals = minDeals;
    // int maxX = baseRep.size() - 1;
    // for (int i = maxX; i >= 1; i--) {
    //     while (baseRep[i]) {
    //         if (curDeals + 2 <= k) {
    //             baseRep[i] -= 1;
    //             baseRep[i-1] += 3;
    //             curDeals += 2;
    //         } else {
    //             break;
    //         }
    //     }
    //     if (baseRep[i])
    //         break;
    // }

    int maxX = baseRep.size() - 1;
    int margin = k - minDeals;

    if (margin == 0)
        goto HERE;

    for (int i = maxX; i >= 1; i--) {
        if (2 * baseRep[i] <= margin) {
            baseRep[i-1] += 3 * baseRep[i];
            margin -= 2 * baseRep[i];
            baseRep[i] = 0;
        } else {
            baseRep[i-1] += 3 * (margin / 2);
            baseRep[i] -= (margin / 2);
            margin = 0;
            break;
        }
    }

    HERE:
    ll cost = 0;
    for (ll i = 0; i < baseRep.size(); i++) {
        cost += baseRep[i] * (ll)(powl(3, i+1) + i * powl(3, i-1));
    }
    cout << cost << '\n';
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