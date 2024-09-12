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
    ll n, arr[2*MAXLEN];
    map <int, int> freq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k = 0;
    int nc, zc, pc;
    nc = zc = pc = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            if (zc < 2) {
                zc++;
                arr[k++] = arr[i];
            }
            continue;
        }
        if (arr[i] < 0 && nc < 2) {
            nc++;
            arr[k++] = arr[i];
            continue;
        }
        if (arr[i] > 0 && pc < 2) {
            pc++;
            arr[k++] = arr[i];
            continue;
        }

        cout << "NO" << '\n';
        return;
    }

    for (int i = 0; i < k; i++) {
        freq[arr[i]]++;
    }

    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            for (int l = j+1; l < k; l++) {
                if (freq[(ll) arr[i]+arr[j]+arr[l]] == 0) {
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
    }

    cout << "YES" << '\n';
    return;
}


int main() {
    // FIXIO;
    //fileio();

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}