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
        ll n, arr[2*MAXLEN];

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ll mx = 0;
        for (int i = 0; i < n ; i++) {
            mx = max(mx, arr[i]);
        }


        if (n&1) {
            bool f = false;
            for (int i = 0; i < n; i++) {
                if (mx == arr[i] && i % 2 == 0) {
                    f = true;
                    break;
                }
            }

            if (f) {
                cout << mx + (n+1)/2 << '\n';
            } else {
                cout << mx + n/2 << '\n';
            }
        } else {
            cout << mx + (n+1)/2 << '\n';
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