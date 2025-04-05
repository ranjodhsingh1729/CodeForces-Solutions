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
        string x;
        cin >> n;
        cin >> x;

        if (x[0] == '1' || x[n-1] == '1') {
            cout << "YES" << '\n';
            return;
        }

        int f = 0, p = (x[0] == '1');
        for (int i = 1; i < n; i++) {
            if (p && x[i] == '1') {
                f = 1; break;
            }

            p = (x[i] == '1');
        }

        if (f) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
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