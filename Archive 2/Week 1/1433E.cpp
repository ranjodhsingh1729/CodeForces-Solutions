#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


ll factorial(int n) {
    ll f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

ll nck(int n, int k) {
    ll ac = 1;
    for (int i = n; i > k; i--) {
        ac *= i;
    }
    return ac/factorial(k);
}

int main() {
    int n;
    cin >> n;
    int k = n/2;

    ll tmp1 = nck(n, k);
    ll tmp2 = factorial(k-1);

    cout << (tmp1/2)*(tmp2*tmp2) << '\n';

    return 0;
}