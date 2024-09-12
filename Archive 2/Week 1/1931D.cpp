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


ll no_of_2sums(int x, int n, int arr[]) {
    map <int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (2*arr[i] == x)
            cnt -= 1;
        cnt += freq[x-arr[i]];
    }

    return cnt;
}


void solve() {
    ll n, x, y, arr[2*MAXLEN];
    vector <pair <int, int>> vpi;

    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        vpi.push_back(make_pair(arr[i]%y, arr[i]%x));
    }
    sort(vpi.begin(), vpi.end());


    int k = 0, brr[2*MAXLEN];
    brr[k++] = 0;
    for (int i = 1; i < n; i++) {
        if (vpi[i].first != vpi[i-1].first)
            brr[k++] = i;
    }

    // for (auto x: vpi) {
    //     cout << x.first << ':' << x.second << '\n';
    // }

    // for (int i = 0; i < k; i++) {
    //     cout << brr[i] << ' ';
    // }
    // cout << '\n';

    ll cnt = 0;
    int m, crr[2*MAXLEN];
    for (int i = 0; i < k; i++) {
        int idx = brr[i];
        int end = (i != k-1 ? brr[i+1] : n);
        m = 0;
        for (int j = idx; j < end; j++) {
            crr[m++] = vpi[j].second;
        }
        cnt += no_of_2sums(x, m, crr)/2;
        cnt += no_of_2sums(0, m, crr)/2;
        // cout << idx << ' ' << end << ' ' << m << ' ' << cnt << '\n';
    }

    cout << cnt << '\n';
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