#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long)((a) - (b) * floor((long double)(a) / (b))))
#define FIXIO                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int, int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pre(r, l) for (ll i = (r); i >= ll((l)); i--)
#define fro(l, r) for (ll i = (l); i <= ll((r)); i++)

void solve()
{
    int n;
    cin >> n;
    vector<int> P(n), S(n);
    for (auto &i : P)
        cin >> i;
    for (auto &i : S)
        cin >> i;

    bool f = 1;
    int g = P[n - 1];

    // MAY WORK (NECESSARY BUT MAY NOT BE SUFFICIENT)
    // for (int i = 1; i < n; i++)
    // {
    //     if (
    //         (P[i - 1] < P[i]) 
    //         || (S[i] < S[i - 1])
    //         || (P[i - 1] % P[i]) 
    //         || (S[i] % S[i - 1]) 
    //         || (gcd(P[i - 1], S[i]) != g)
    //         || (gcd(S[i - 1], P[i]) != g)
    //     )
    //     {
    //         f = 0;
    //         break;
    //     }
    // }

    // THIS IF RIGHT WILL DEFINATELY WORK (GENERATING A AND THEN P AND S) 
    vector<ll> A(n);
    A[0] = P[0], A[n-1] = S[n-1];
    for (int i = 1; i < n-1; i++) {
        A[i] = lcm((ll) P[i], (ll) S[i]);
    }
    
    vector<int> P1(n), S1(n);
    P1[0] = A[0], S1[n-1] = A[n-1];
    for (int i = 1; i < n; i++) {
        P1[i] = gcd(P[i-1], A[i]);
        S1[n-i-1] = gcd(S[n-i], A[n-i-1]);
    }
    for (int i = 0; i < n; i++) {
        if (P1[i] != P[i] || S1[i] != S[i]) {
            f = 0; break;
        }
    }

    cout << (f ? "YES" : "NO") << endl;
}

int main()
{
    FIXIO;

    ll t;
    t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}