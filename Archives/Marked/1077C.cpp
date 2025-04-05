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
    ll n;
    ll arr[2*MAXLEN];
    ll *brr[2*MAXLEN];

    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        brr[i] = arr+i;

        sum += arr[i];
    }
    sort(brr, brr+n, [](auto a, auto b) {
        return *a < *b;
    });

    set <int> indices;

    ll l, r, tmp;
    for (int i = 0; i < n; i++) {
        if ((sum-*brr[i])&1)
            continue;
        
        tmp = (sum-*brr[i])/2;

        l = lower_bound(brr, brr+n, &tmp, [](auto a, auto b) { return *a < *b; }) - brr;
        r = upper_bound(brr, brr+n, &tmp, [](auto a, auto b) { return *a < *b; }) - brr;

        if (l >= n || tmp != *brr[l])
            continue;

        if (r - l > 1 || i != l)
            indices.insert((brr[i]-arr)+1);
    }

    cout << indices.size() << '\n';
    for (auto i: indices) {
        cout << i << ' ';
    }
    cout << '\n';
}


int main() {
    FIXIO;
    //fileio();

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}