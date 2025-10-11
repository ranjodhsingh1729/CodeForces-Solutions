#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pre(r, l) for (ll i = (r); i >= ll((l)); i--)
#define fro(l, r) for (ll i = (l); i <= ll((r)); i++)


struct FenwickTree {
    int n;
    vector<int> T;

    FenwickTree(int len) {
        this->n = len;
        this->T.assign(n, 0);
    }

    ll sum(int r) {
        ll res = 0;
        while (r >= 0) {
            res += T[r];
            r = (r & (r + 1)) - 1;
        }
        return res;
    }

    void add(int i, int delta) {
        while (i < n) {
            T[i] += delta;
            i = (i | (i + 1));
        }
    }
};


// int binsrch(int k, int n, vector<int> A, FenwickTree F) {
//     int l = 0, h = n, p;
//     while (l < h) {
//         p = (l+h)/2;
//         if (F.sum(A[p]) < k) {
//             l = p+1;
//         } else {
//             h = p;
//         }
//     }

//     return l;
// }


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &i: A) cin >> i;

    vector<int> B = A;
    sort(all(B));
    B.resize(k);

    vector<int> C;
    int x = B[k-1];
    for (auto &i: A) if (i <= x) C.push_back(i);

    int c = C.size() - k + 1;

    bool f = true;
    int l = 0, r = C.size()-1;
    while (l < r) {
        if (C[l] == C[r]) {
            l++, r--; continue;
        }

        if ((C[l] == x || C[r] == x) && c != 0) {
            if (C[l] == x) l++;
            else r--;

            c--;
        } else {
            f = 0;
            break;
        }
    }

    cout << ( f ? "YES" : "NO" ) << endl;
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