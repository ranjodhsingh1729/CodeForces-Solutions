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
    ll n;
    cin >> n;
    vector<int> A(n), B(n);
    for (auto &i: A) cin >> i;
    for (auto &i: B) cin >> i;

    /*
        can perform ai = ai ^ ai+1 at most once for each i
        tell if its possible to turn ai into ai+1.

        lets first solve for binary numbers and then generalize for integers.

        lets say we have the following arrays
        3
        0 0 1
        1 0 1
            last 1 can't change it self
            if next element is one we can flip
            if next element isn't one we can't flip 
        5
        1 0 1 0 1
        1 0 1 1 1
            yes
            
        you can use the current state and the modified state (if modification results in equality)
        of the next element for you modification.

        start from behind use both ai and bi untill you encounter an array which you can't change.
    */

    bool f = A[n-1] == B[n-1];
    for (int i = n-2; f && i >= 0; i--) {
        if (A[i] == B[i]) {
            continue;
        } else {
            if ((A[i] ^ A[i+1]) == B[i] || (A[i] ^ B[i+1]) == B[i]) {
                continue;
            } else {
                f = false;
            }
        }
    }

    cout << (f ? "YES" : "NO") << '\n';
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