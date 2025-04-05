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
    ll n, k, tmp;
    map <int, int> freq;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        freq[tmp]++;
    }

    ll p = 0;
    ll nz = n, pnz = n;
    ll sum = 0, steps = 0;
    for (auto x: freq) {
        if (sum + (nz * (x.first - p)) >= k) {
            tmp =  ((k - sum) / nz) * nz;
            sum += tmp;
            steps += tmp + freq[p];

            break;
        } else {
            tmp = nz * (x.first - p);
            sum += tmp;
            steps += tmp + freq[p];
        }
        
        pnz = nz;
        p = x.first;
        nz -= x.second;
    }
    steps += k - sum;


    cout << steps << '\n';

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