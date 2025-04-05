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
    cin >> n;
    ll arr[2*MAXLEN];
    map <ll, int> freq;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        freq[arr[i]]++;
    }

    ll tmp;
    set <int> indices;
    for (int i = 0; i < n; i++) {
        tmp = sum-arr[i];
        if (tmp&1)
            continue;
        tmp /= 2;
        
        freq[arr[i]]--;

        if (freq[tmp] > 0) {
            indices.insert(i+1);
        }

        freq[arr[i]]++;
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