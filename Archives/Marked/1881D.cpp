#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int SIEVE[1000001] = { 0 };


void fileio() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

int pf_count(int x, int y) {
    int i = 0;
    while (y % x == 0) {
        y /= x;
        i++;
    }
    return i;
}

void solve() {
    ll n;
    cin >> n;
    ll temp;
    map <int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (SIEVE[temp] == 0) {
            freq[temp] += 1;
            continue;
        }
        for (int i = 2; i <= sqrtl(temp); i++) {
            if (temp % i == 0) {
                int r1 = i;
                int r2 = temp / i;
                if (SIEVE[r1] == 0)
                    freq[r1] += pf_count(r1, temp);
                if (r1 != r2 && SIEVE[r2] == 0)
                    freq[r2] += pf_count(r2, temp);
            }
        }
    }

    bool f = false;
    for (auto &x: freq) {
        if (x.second % n) {
            f = true; break;
        }
    }

    if (f) 
        cout << "NO";
    else
        cout << "YES";

    cout << '\n';
}


int main() {
    FIXIO;
    //fileio();

    ll t;
    // t = 1;
    cin >> t;

    SIEVE[0] = 1;
    SIEVE[1] = 1;
    for (int i = 2; i <= 1E6; i++) {
        for (int j = 2; i*j <= 1E6; j++) {
            SIEVE[i*j] = 1;
        }
    }


    while (t--) {
        solve();
    }

    return 0;
}