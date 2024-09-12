#include <bits/stdc++.h>
 
#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
 
 
void fileio() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}
 
void solve() {
    ll a, b;
    cin >> a >> b;
    cout << b - a << '\n';    
}
 
 
int main() {
    FIXIO;
 
    ll t;
    // t = 1;
    cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}