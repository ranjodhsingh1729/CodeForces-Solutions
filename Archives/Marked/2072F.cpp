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


void solve(vector<int> &A) {
    ll n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cout << k * (A[n-1] == A[i] + A[n-1-i]) << ' ';
    }
    cout << '\n';
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    cin >> t;

    vector<int> A(1000000+69);
    A[0] = A[1] = 0;
    for (int i = 2; i < 1000000+69; i++) {
        A[i] = A[i-1];
        int x = i;
        while (x % 2 == 0) {
            x /= 2; A[i]++;
        }
    }

    while (t--) {
        solve(A);
    }

    return 0;
}