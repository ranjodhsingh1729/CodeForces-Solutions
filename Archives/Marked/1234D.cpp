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

    void build(int node, int tl, int tr, string &arr) {
        if (tl == tr) {
            T[node] = 1 << (arr[tl]-'a');
        } else {
            int mid = tl+(tr-tl)/2;
            build(left(node), tl, mid, arr);
            build(right(node), mid+1, tr, arr);
            
            int l = T[left(node)], r = T[right(node)];
            T[node] = l | r;
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
            int l = T[left(node)], r = T[right(node)];
            T[node] = l | r;
        } 
    }

    int sum(int node, int tl, int tr, int ql, int qr) {
        if (ql == tl && qr == tr) {
            return T[node];
        }

        int mid = tl+(tr-tl)/2;
        if (qr <= mid) {
            return sum(left(node), tl, mid, ql, qr);
        } else if (ql > mid) {
            return sum(right(node), mid+1, tr, ql, qr);
        } else {
            int l = sum(left(node), tl, mid, ql, mid);
            int r = sum(right(node), mid+1, tr, mid+1, qr);
            return l | r;
        }
    }
};


void solve() {
    string x;
    cin >> x;
    int n, q;
    n = x.size(); cin >> q;

    char c;
    int t, l, r;
    SegmentTree SG(n);
    SG.build(0, 0, n-1, x);
    while (q--) {
        cin >> t >> l;
        if (t == 1) {
            l--; cin >> c;
            SG.update(0, 0, n-1, l, (1 << (c-'a')));
            continue; 
        }

        // for (auto val: SG.T) {
        //     int count = 0;
        //     while (val) count += val&1, val = val>>1;
        //     cout << count << ' ';
        // }
        // cout << '\n';

        cin >> r; l--, r--;
        int count = 0;
        int val = SG.sum(0, 0, n-1, l, r);
        while (val) {
            count += (val&1);
            val = (val>>1);
        }
        cout << count << '\n';
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