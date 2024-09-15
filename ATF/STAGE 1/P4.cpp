#include <bits/stdc++.h>
 
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
 
using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;
 
const ll MAX_SUM = 2e5*1e9;


int check(int k, ll mn_sm, int n, int arr[]) {
    // if (mn_sm > ceil((double) tt_sm / k)) return false;

    ll s = 0, sm = 0;
    for (int i = 0; i < n; i++) {
        sm += arr[i];
        if (sm >= mn_sm) {
            s++;
            sm = 0;
        }
    }

    return s>=k;
}


int main() {
    int n, k;
    cin >> n >> k;
    int arr[MAXN];

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    ll l = 1, r = MAX_SUM, p;
    while (l <= r) {
        p = (l+r)/2;
        if (check(k, p, n, arr)) {
            l = p+1;
        } else {
            r = p-1;
        }
    }


    cout << l-1 << '\n';
 
    return 0;
}
