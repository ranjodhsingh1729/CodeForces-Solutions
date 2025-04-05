    #include <bits/stdc++.h>

    #define MAXLEN 100001
    #define min(a, b) ((a) < (b) ? (a) : (b))
    #define max(a, b) ((a) > (b) ? (a) : (b))
    #define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
    #define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    using namespace std;
    typedef long long ll;
    typedef array<int, 3> triple;
    const ll MOD = 1e9+7;
    const int MAXN = 1e6+1;
    const ll INF = 0x3f3f3f3f3f3f3f3f;


    void solve() {
        ll n, k;
        cin >> n >> k;
        vector <int> via(n, 0);
        vector <int> vib(n, 0);
        for (int i = 0; i < n; i++)
            cin >> via[i];

        ll a, b;
        while (k--) {
            cin >> a >> b;
            vib[a-1]++; 
            if (b < n) vib[b]--;
        }

        for (int i = 1; i < n; i++) {
            vib[i] += vib[i-1];
        }
        sort(via.begin(), via.end());
        sort(vib.begin(), vib.end());


        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (ll) via[i] * (ll) vib[i];
        }
        cout << sum << '\n';
        
    }


    int main() {
        FIXIO;

        ll t;
        t = 1;
        // cin >> t;

        while (t--) {
            solve();
        }

        return 0;
    }