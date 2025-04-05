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
    ll n;
    cin >> n;
    ll arr[MAXLEN*2], brr[MAXLEN][2];

    ll k = 0;
    for (int i = 0; i < n; i++) {
        cin >> brr[i][0] >> brr[i][1];

        arr[k++] = brr[i][0];
        arr[k++] = brr[i][1];
    }
    sort(arr, arr+k);

    int a, b, tmp;
    vector <pair <int, int>> vpi;
    for (int i = 0; i < n; i++) {
        a = lower_bound(arr, arr+k, brr[i][0]) - arr;
        b = lower_bound(arr, arr+k, brr[i][1]) - arr;

        if (a > b) {
            a--;
        }
        if (b > a) {
            b--;
        }

        vpi.push_back(make_pair(a+b, i));
    }
    sort(vpi.begin(), vpi.end());

    for (int i = 0; i < n; i++) {
        tmp = vpi[i].second;
        cout << brr[tmp][0] << ' ';
        cout << brr[tmp][1] << ' ';
    }
    cout << '\n';

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