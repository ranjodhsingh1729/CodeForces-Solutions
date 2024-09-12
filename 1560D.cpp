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

vector <string> P2;

string inttostr(ll n) {
    string x;
    while (n) {
        x.push_back(n % 10 + '0');
        n /= 10;
    }
    reverse(x.begin(), x.end());
    return x;
}

void solve() {
    ll n;
    cin >> n;
    string x = inttostr(n);
    int m = x.size();


    int k, j, tmp, best = 10;
    for (int i = 0; i < 60; i++) {
        tmp = 0; 
        for (k = 0, j = 0; j < m && k < P2[i].size(); k++) {
            while (j < m && x[j] != P2[i][k])
                j++;
            if (j < m)
                j++, tmp++;
        }
        // cout << P2[i] << '\n';
        // cout << P2[i].size() << ' ' << tmp << ' ' << m-tmp+P2[i].size()-tmp << '\n';
        best = min(best, m-tmp+P2[i].size()-tmp);
    }

    cout << best << '\n';
}

int main() {
    FIXIO;
    //fileio();

    ll t;
    // t = 1;
    cin >> t;

    for (int i = 0; i < 60; i++) {
        P2.push_back(inttostr(powl(2, i)));
    }
    
    while (t--) {
        solve();
    }

    return 0;
}