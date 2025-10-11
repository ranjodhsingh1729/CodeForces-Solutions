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
    int n;
    cin >> n;
    vector<ll> A(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> A[i];
    }

    // AAAADDDD
    // AAADADDD
    // AADADADD
    // ADADADAD

    vector<ll> sumC(2*n+1);
    sumC[0] = 0;
    for (int i = 0; i < 2*n; i++) {
        sumC[i+1] += sumC[i];
        sumC[i+1] += ((i % 2) ? A[i] : -A[i]);
    }
    
    ll ans, sum = 0;
    for (int i = 1; i <= n; i++) {
        ans = (i % 2 ? 1 : -1) * (sumC[2*n-i+1] - sumC[i-1]);
        ans += sum;
        cout << ans << ' ';
        sum += A[2*n-i] - A[i-1];
    }
    cout << '\n';
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