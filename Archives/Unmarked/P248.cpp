#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;


void fileio() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}


int main() {
    FIXIO;
    fileio();

    ll t;
    cin >> t;


    ll alice, bob;
    ll n, k, arr[2*MAXLEN];
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr+n);

        bool f = true;
        alice = bob = 0;
        for (int i = n-1; i >= 0; i--) {
            if (f) {
                alice += arr[i];
            } else {
                bob += arr[i] + min(k, arr[i+1]-arr[i]);
                k -= min(k, arr[i+1]-arr[i]);
            }
            f ^= 1;
        }
        
        cout << alice-bob << '\n';
    }

    return 0;
}