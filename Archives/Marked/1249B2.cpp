#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    ll n;
    cin >> n;
    vector <int> via(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> via[i];
    }

    int jp, jc;
    jp = jc = 0;
    vector <int> vib(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vib[i]) {
            jc = 1;
            jp = via[i];
            while (jp != i) jp = via[jp], jc++;
            vib[i] = jc;
            jp = via[i];
            while (jp != i) vib[jp] = vib[i], jp = via[jp];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << vib[i] << ' ';
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