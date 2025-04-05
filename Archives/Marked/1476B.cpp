#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

void init_io() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

int main() {
    init_io();

    int t;
    cin >> t;

    double temp;
    ll summ, diff;
    int n, k, arr[4*MAXLEN];
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        diff = 0, summ = arr[0];
        for (int i = 1; i < n; i++) {
            temp = (100LL*arr[i]) - (summ*k);
            if (temp > 0) {
                temp /= k;
                diff += ceil(temp);
                summ += ceil(temp);
            }
            summ += arr[i];
        }
        

        cout << diff << '\n';
    }

    return 0;
}