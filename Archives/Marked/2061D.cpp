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
    vector<int> A(n), B(m);
    for (auto &i: A) cin >> i;
    for (auto &i: B) cin >> i;

    map<int, int> freqA, freqB;
    for (auto &i: A) freqA[i]++;
    for (auto &i: B) freqB[i]++;

    priority_queue<int> q;
    for (auto &i: freqB) {
        if (i.second > freqA[i.first]) {
            q.push(i.first);
        }
    }

    while (!q.empty()) {
        int curr = q.top(); q.pop();
        if (curr == 1) break;
        
        int divs = freqB[curr]-freqA[curr];
        if (divs == 0)
            continue;

        freqB[curr] -= divs;
        freqB[curr/2] += divs;
        freqB[(curr+1)/2] += divs;

        if (freqB[curr/2] > freqA[curr/2])
            q.push(curr/2);
        if (curr/2 != (curr+1)/2)
            if (freqB[(curr+1)/2] > freqA[(curr+1)/2])
                q.push((curr+1)/2);
    }

    for (auto &i: freqB) {
        // cout << i.first << ':' << i.second << ' ';
        if (i.second != freqA[i.first]) {
            cout << "NO" << '\n';
            return;
        }
    }
    // cout << '\n';

    for (auto &i: freqA) {
        // cout << i.first << ':' << i.second << ' ';
        if (i.second != freqB[i.first]) {
            cout << "NO" << '\n';
            return;
        }
    }
    // cout << '\n';

    cout << "YES" << '\n';

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