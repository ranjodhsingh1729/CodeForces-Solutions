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
    
// struct FenwickTree
// {
//     int n;
//     vector<ll> BIT;

//     FenwickTree(int n)
//     {
//         this->n = n;
//         BIT.assign(n, 0);
//     }

//     FenwickTree(const vector<ll> &a) : FenwickTree(a.size())
//     {
//         for (size_t i = 0; i < a.size(); i++)
//         {
//             add(i, a[i]);
//         }
//     }

//     ll sum(int r)
//     {
//         ll res = 0;
//         for (; r >= 0; r = (r & (r + 1)) - 1)
//         {
//             res += BIT[r];
//         }
//         return res;
//     }

//     ll sum(int l, int r)
//     {
//         return sum(r) - sum(l - 1);
//     }

//     void add(int idx, ll delta)
//     {
//         for (; idx < n; idx = idx | (idx + 1))
//         {
//             BIT[idx] += delta;
//         }
//     }
// };

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    if (n < 3)
    {
        cout << "NO" << '\n';
        return;
    }

    vector<ll> b(n + 1), s(n + 1);
    
    s[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        b[i] = (a[i] <= k ? 1 : -1);
        s[i] = s[i - 1] + b[i];
    }

    vector<bool> pregd(n + 1, false);
    for (ll l = 1; l <= n; l++)
    {
        ll need = (l % 2 == 0 ? 0 : 1);
        if (s[l] >= need)
            pregd[l] = true;
    }

    vector<bool> sufgd(n + 1, false);
    for (ll r = 1; r <= n; r++)
    {
        ll len = n - r;
        if (len < 1)
            continue;
        ll need = (len % 2 == 0 ? 0 : 1);
        if (s[n] - s[r] >= need)
            sufgd[r] = true;
    }

    bool ok = false;
    ll min_l = n + 1;
    for (ll l = 1; l <= n - 2; l++)
    {
        if (pregd[l])
        {
            min_l = l;
            break;
        }
    }
    ll max_r = -1;
    for (ll r = n - 1; r >= 2; r--)
    {
        if (sufgd[r])
        {
            max_r = r;
            break;
        }
    }
    if (min_l < max_r)
        ok = true;

    if (!ok)
    {
        ll min_even = INF, min_odd = INF;
        for (ll r = 2; r <= n - 1; r++)
        {
            ll l = r - 1;
            if (pregd[l])
            {
                if (l % 2 == 0)
                    min_even = min(min_even, s[l]);
                else
                    min_odd = min(min_odd, s[l]);
            }
            if (min_even < INF)
            {
                ll thr = s[r] - (r % 2 ? 1 : 0);
                if (min_even <= thr)
                {
                    ok = true;
                    break;
                }
            }
            if (min_odd < INF)
            {
                ll thr = s[r] - (r % 2 ? 0 : 1);
                if (min_odd <= thr)
                {
                    ok = true;
                    break;
                }
            }
        }
    }

    if (!ok)
    {
        vector<ll> b2(n + 1), s2(n + 1);
        s2[0] = 0;
        for (ll i = 1; i <= n; i++)
        {
            b2[i] = b[n + 1 - i];
            s2[i] = s2[i - 1] + b2[i];
        }
        vector<bool> pregd2(n + 1, false);
        for (ll l = 1; l <= n; l++)
        {
            ll need = (l % 2 == 0 ? 0 : 1);
            if (s2[l] >= need)
                pregd2[l] = true;
        }
        ll min_even = INF, min_odd = INF;
        for (ll r = 2; r <= n - 1; r++)
        {
            ll l = r - 1;
            if (pregd2[l])
            {
                if (l % 2 == 0)
                    min_even = min(min_even, s2[l]);
                else
                    min_odd = min(min_odd, s2[l]);
            }
            if (min_even < INF)
            {
                ll thr = s2[r] - (r % 2 ? 1 : 0);
                if (min_even <= thr)
                {
                    ok = true;
                    break;
                }
            }
            if (min_odd < INF)
            {
                ll thr = s2[r] - (r % 2 ? 0 : 1);
                if (min_odd <= thr)
                {
                    ok = true;
                    break;
                }
            }
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
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