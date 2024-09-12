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
    ll n, k;
    cin >> n >> k;

    int tmp;
    map <int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        freq[tmp]++;
    }

    vector <int> vi;
    for (auto x: freq) {
        if (x.second >= k) {
            vi.push_back(x.first);
        }
    }
    int x = vi.size();

    if (x == 0) { 
        cout << -1 << '\n';
        return;
    }

    if (x == 1 && k >= 1) {
        cout << vi[0] << ' ' << vi[0] << '\n';
        return;
    }


    int l, r;
    int curr, best;
    tmp = l = vi[0];
    r = best = -1;
    for (int i = 1; i < x; i++) {
        if (vi[i]-vi[i-1] != 1) {
            curr = vi[i-1] - tmp;
            if (curr > best) {
                l = tmp;
                r = vi[i-1];
                best = r-l;
            }
            tmp = vi[i];
        }
    }

    if (tmp != vi[x-1]) {
        curr = vi[x-1] - tmp;
        if (curr > best) {
            l = tmp;
            r = vi[x-1];
            best = r-l;
        }
    }

    if (best != -1) {
        cout << l << ' ' << r << '\n';
    } else {
        cout << best << '\n';
    }
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