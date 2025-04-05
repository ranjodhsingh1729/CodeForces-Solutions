#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n, k, arr[MAXLEN];
    cin >> n >> k;
    map <int, int> mapa;
    for (int i = 0; i < 2*n; i++) {
        cin >> arr[i];
        if (i < n) mapa[arr[i]]++;
    }

    vector<int> p, q, r;
    for (int i = 1; i <= n; i++) {
        switch (mapa[i]) {
            case 0:
                p.push_back(i);
                break;
            case 1:
                q.push_back(i);
                break;
            case 2:
                r.push_back(i);
                break;
            default:
                break;
        }
    }
    
    int a, b, c;
    a = p.size();
    b = q.size();
    c = r.size();


    int i = 0, z;
    for (i = 0; i < c && i < k; i++) {
        cout << r[i] << ' ' << r[i] << ' ';
    }
    for (i *= 2, z = 0; z < b && i < 2*k; i++) {
        cout << q[z++] << ' ';
    }
    cout << '\n';
    for (i = 0; i < a && i < k; i++) {
        cout << p[i] << ' ' << p[i] << ' ';
    }
    for (i *= 2, z = 0; z < b && i < 2*k; i++) {
        cout << q[z++] << ' ';
    }
    cout << '\n';
    
}


int main() {
    FIXIO;

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}