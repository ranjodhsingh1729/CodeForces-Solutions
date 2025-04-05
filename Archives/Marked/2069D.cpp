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


bool check(vector<int> &a, vector<int> &b) {
    for (int i = 97; i < 123; i++) {
        if (2*a[i] < b[i])
            return false;
    }
    return true;
}


void solve() {
    string x;
    cin >> x;
    int n = x.size();

    int a;
    for (a = 0; a < n/2; a++) {
        if (x[a] != x[n-a-1]) {
            break;
        }
    }
    if (a == n/2) {
        cout << 0 << '\n';
        return;
    }

    int b;
    for (b = n/2; b < n; b++) {
        if (x[b] != x[n-b-1]) {
            break;
        }
    }

    vector<int> F(256, 0);
    vector<int> P(256, 0);
    if (b > n/2) {
        b = n-b-1;
        for (int i = a; i <= b; i++) {
            F[x[i]]++;
            P[x[n-i-1]]++;
        }
        int f = 1;
        for (int i = 97; i < 123; i++) {
            if (F[i] != P[i]) {
                f = 0; break;
            }
        }
        if (f) {
            cout << (b-a+1) << '\n';
            return;
        }
    }
    
    b = n-a;
    fill(F.begin(), F.end(), 0);
    for (int i = a; i < b; i++) {
        F[x[i]]++;
    }

    int ans = b-a;
    fill(P.begin(), P.end(), 0);
    for (int i = a; i < b; i++) {
        P[x[i]]++;
        if (check(P, F)) ans = min(ans, i-a+1);
    }

    fill(P.begin(), P.end(), 0);
    for (int i = b-1; i >= a; i--) {
        P[x[i]]++;
        if (check(P, F)) ans = min(ans, b-i);
    }

    cout << ans << '\n';
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