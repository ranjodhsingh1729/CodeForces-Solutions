#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MAXLEN 100001
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pre(r, l) for (ll i = (r); i >= ll((l)); i--)
#define fro(l, r) for (ll i = (l); i <= ll((r)); i++)


void solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<vector<ll>> A(n, vector<ll>(m, 0));
    vector<vector<ll>> Z(n, vector<ll>(m, 0));
    
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            A[n-i-1][j] = c == 'X';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++ ) {
            Z[i][j] = A[i][j];
        }
    }

    int left, right;
    vector<ll> C(m, 0);
    vector<vector<ll>> B(n, vector<ll>(m, 0));
    B[0][0] = A[0][0];
    for (int j = 1; j < m; j++) {
        B[0][j] = 0;
        B[0][j] = A[0][j] + B[0][j-1];
    }
    for (int j = 0; j < m; j++) {
        if (!Z[0][j]) continue;

        left = j-d-1;
        right = j+d;
        A[0][j] = mod(((right < m ? B[0][right] : B[0][m-1]) - (left >= 0 ? B[0][left] : 0)), 998244353);
    }
    B[0][0] = A[0][0];
    for (int j = 1; j < m; j++) {
        B[0][j] = 0;
        B[0][j] += A[0][j] + B[0][j-1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!Z[i][j]) continue;

            left = ceill(j-sqrtl(d*d-1))-1;
            right = floorl(j+sqrtl(d*d-1));
            A[i][j] = mod(((right < m ? B[i-1][right] : B[i-1][m-1]) - (left >= 0 ? B[i-1][left] : 0)), 998244353);
        }
        C = A[i];
        for (int j = 1; j < m; j++) {
            C[j] += C[j-1];
        }


        for (int j = 0; j < m; j++) {
            if (!Z[i][j]) continue;
          
            left = j-d-1;
            right = j+d;
            A[i][j] = mod(((right < m ? C[right] : C[m-1]) - (left >= 0 ? C[left] : 0)), 998244353);
        }
        B[i][0] = A[i][0];
        for (int j = 1; j < m; j++) {
            B[i][j] = 0;
            B[i][j] += A[i][j] + B[i][j-1];
        }
    }

    cout << mod(B[n-1][m-1], 998244353)  << '\n';
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}