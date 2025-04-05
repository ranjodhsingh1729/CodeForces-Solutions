#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n, arr[2*MAXLEN];
    cin >> n; 
    for (int i = 0; i < n ; i++) {
        cin >> arr[i];
    }

    ll temp = 0;
    cout << temp << ' ';
    for (int i = 0; i < n-1; i++) {
        temp = arr[i] & arr[i+1];
        temp = (temp != arr[i]) ? (temp ^ arr[i]) : 0;
        cout << temp << ' ';
        arr[i+1] = temp ^ arr[i+1]; 
    }
    cout << '\n';
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