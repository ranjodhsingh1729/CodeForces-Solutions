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



#define parent(n) ((n+1)/2)-1
#define left(n) (2*(n+1))-1
#define right(n) (2*(n+1)+1)-1

struct SegmentTreeGCD {
    int n;
    vector<int> T;

    SegmentTreeGCD(int n) {
        this->n = n;
        this->T.assign(4*n, 0);
    }

    void build(int node, int tl, int tr, vector<int> &arr) {
        if (tl == tr) {
            T[node] = arr[tl];
        } else {
            int mid = tl+(tr-tl)/2;
            build(left(node), tl, mid, arr);
            build(right(node), mid+1, tr, arr);

            T[node] = gcd(T[left(node)], T[right(node)]);
        }
    }

    void update(int node, int tl, int tr, int idx, int val) {
        if (tl == tr) {
            T[node] = val;
        } else {
            int mid = tl+(tr-tl)/2;
            if (idx <= mid) {
                update(left(node), tl, mid, idx, val);
            } else {
                update(right(node), mid+1, tr, idx, val);
            }

            T[node] = gcd(T[left(node)], T[right(node)]);
        } 
    }

    int get(int node, int tl, int tr, int ql, int qr) {
        if (ql == tl && qr == tr) {
            return T[node];
        }

        int mid = tl+(tr-tl)/2;
        if (qr <= mid) {
            return get(left(node), tl, mid, ql, qr);
        } else if (ql > mid) {
            return get(right(node), mid+1, tr, ql, qr);
        } else {
            return gcd(
                get(left(node), tl, mid, ql, mid),
                get(right(node), mid+1, tr, mid+1, qr)
            );
        }
    }
};

struct SegmentTreeMinC {
    int n;
    vector<pair<int,int>> T;

    SegmentTreeMinC(int n) {
        this->n = n;
        this->T.assign(4*n, {0,0});
    }

    pair<int,int> combine(pair<int,int> A, pair<int,int> B) {
        if (A.second < B.second) {
            return A;
        }
        if (A.second > B.second) {
            return B;
        }

        return {A.first+B.first, A.second};
    }

    void build(int node, int tl, int tr, vector<int> &arr) {
        if (tl == tr) {
            T[node] = {1, arr[tl]};
        } else {
            int mid = tl+(tr-tl)/2;
            build(left(node), tl, mid, arr);
            build(right(node), mid+1, tr, arr);

            T[node] = combine(T[left(node)], T[right(node)]);
        }
    }

    void update(int node, int tl, int tr, int idx, int val) {
        if (tl == tr) {
            T[node] = {1, val};
        } else {
            int mid = tl+(tr-tl)/2;
            if (idx <= mid) {
                update(left(node), tl, mid, idx, val);
            } else {
                update(right(node), mid+1, tr, idx, val);
            }

            T[node] = combine(T[left(node)], T[right(node)]);
        } 
    }

    pair<int,int> get(int node, int tl, int tr, int ql, int qr) {
        if (ql == tl && qr == tr) {
            return T[node];
        }

        int mid = tl+(tr-tl)/2;
        if (qr <= mid) {
            return get(left(node), tl, mid, ql, qr);
        } else if (ql > mid) {
            return get(right(node), mid+1, tr, ql, qr);
        } else {
            return combine(
                get(left(node), tl, mid, ql, mid),
                get(right(node), mid+1, tr, mid+1, qr)
            );
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &i: A) cin >> i;

    SegmentTreeGCD HCF(n);
    HCF.build(0, 0, n-1, A);

    SegmentTreeMinC Minc(n);
    Minc.build(0, 0, n-1, A);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int c = HCF.get(0, 0, n-1, a-1, b-1);
        pair<int,int> d = Minc.get(0, 0, n-1, a-1, b-1);

        if (c == d.second) {
            cout << b-a+1-d.first << '\n';
        } else {
            cout << b-a+1 << '\n';
        }
    }
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