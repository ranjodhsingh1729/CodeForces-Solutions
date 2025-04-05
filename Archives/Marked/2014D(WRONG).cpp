#include <bits/stdc++.h>

#define MAXLEN 100001
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
    ll n, d, k;
    cin >> n >> d >> k;

    ll a, b;
    ll arr[100005] = { 0 };
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        arr[a]++;
        arr[b+1]--;
    }

    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i-1];
    }

    ll ranges = n-d+1;
    multiset <int> range;

    for (int i = 1; i <= d; i++) {
        range.insert(arr[i]);
    }

    ll cur = *(range.rbegin());
    ll globminidx = 1, globmaxidx = 1;
    ll globminval = cur, globmaxval = cur;

    cout << cur << '\n';

    for (int i = d+1; i <= n; i++) {
        range.insert(arr[i]);
        range.extract(arr[i-d]);
        cur = *(range.rbegin());

        if (cur < globminval) {
            globminval = cur;
            globminidx = i-d+1;
        }

        if (cur > globmaxval) {
            globmaxval = cur;
            globmaxidx = i-d+1;
        }
    }

    cout << globmaxidx << ' ' << globminidx << '\n';
    cout << globmaxval << ' ' << globminval << '\n';

}


int main() {
    FIXIO;
    //fileio();

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}