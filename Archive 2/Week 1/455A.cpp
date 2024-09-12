#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 1e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


map <int, ll> freq;
int main() {
    int n, arr[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]] += arr[i];
    }

    ll prev = 0, curr = freq[1], temp;
    for (int i = 2; i <= MAXN; i++) {
        temp = max(curr, prev+freq[i]);
        prev = curr;
        curr = temp;
    }

    cout << curr << '\n';

    return 0;
}