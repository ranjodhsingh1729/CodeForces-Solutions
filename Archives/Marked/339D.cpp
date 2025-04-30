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
struct SegmentTree {
    int n;
    vector<int> T;

    SegmentTree(int n) {
        this->n = n;
        this->T.assign(4*n, 0);
    }

    void build(int node, bool f, int tl, int tr, vector<int> &arr) {
        if (tl == tr) {
            T[node] = arr[tl];
        } else {
            int mid = tl+(tr-tl)/2;
            build(left(node), !f, tl, mid, arr);
            build(right(node), !f, mid+1, tr, arr);
            
            int l = T[left(node)], r = T[right(node)];
            T[node] = f ? (l | r) : (l ^ r);
        }
    }

    void update(int node, bool f, int tl, int tr, int idx, int val) {
        if (tl == tr) {
            T[node] = val;
        } else {
            int mid = tl+(tr-tl)/2;
            if (idx <= mid) {
                update(left(node), !f, tl, mid, idx, val);
            } else {
                update(right(node), !f, mid+1, tr, idx, val);
            }
            int l = T[left(node)], r = T[right(node)];
            T[node] = f ? (l | r) : (l ^ r);
        }
    }

    ll sum(int node, bool f, int tl, int tr, int ql, int qr) {
        if (ql == tl && qr == tr) {
            return T[node];
        }

        int mid = tl+(tr-tl)/2;
        if (qr <= mid) {
            return sum(left(node), !f, tl, mid, tl, qr);
        } else if (ql > mid) {
            return sum(right(node), !f, mid+1, tr, ql, tr);
        } else {
            int l = sum(left(node), !f, tl, mid, tl, qr);
            int r = sum(right(node), !f, mid+1, tr, ql, tr);
            return f ? (l | r) : (l ^ r);
        }
    }
};



void solve() {
    ll n, m;
    cin >> n >> m;
    vector<int> A((1<<n));
    for(auto &i: A) cin >> i;

    int a, b;
    SegmentTree SG((1<<n));
    SG.build(0, n&1, 0, (1<<n)-1, A);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        // for (auto &i: SG.T) {
        //     cout << i << ' ';
        // }
        // cout << '\n';

        SG.update(0, n&1, 0, (1<<n)-1, a-1, b);
        cout << SG.sum(0, n&1, 0, (1<<n)-1, 0, (1<<n)-1) << '\n';
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