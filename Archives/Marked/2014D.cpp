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
    map <int, int> freqs;
    map <int, int> freqe;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        freqs[a]++;
        freqe[b]++;
    }

    ll cur = 0, tmp = 0;
    for (int i = 1; i <= d; i++) {
        tmp += freqs[i];
        cur = max(cur, tmp);
    }

    ll globminidx = 1, globmaxidx = 1;
    ll globminval = cur, globmaxval = cur;
    for (int i = d+1; i <= n; i++) {
        cur += freqs[i];
        cur -= freqe[i-d];

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