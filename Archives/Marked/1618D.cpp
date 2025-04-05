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
    ll n, k, arr[2*MAXLEN];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);


    ll score = 0;
    int idx = n-k-k;

    int best = 0;
    map <int, int> freq;
    for (int i = idx; i < n; i++) {
        freq[arr[i]]++;
        best = max(best, freq[arr[i]]);
    }

    score += (k-best >= 0 ? 0 : best-k);

    for (int i = 0; i < idx; i++) {
        score += arr[i];
    }

    cout << score << '\n';
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