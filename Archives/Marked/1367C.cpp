#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

#define inbounds(x, l, r) ((x) >= (l) && (x) < (r))

void init_io() {
    #ifndef ONLINE_JUDGE
    freopen("streams/input.txt", "r", stdin);
    freopen("streams/output.txt", "w", stdout);
    #endif
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init_io();

    int t;
    cin >> t;

    int n, k;
    char arr[MAXLEN * 3];
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        // arr[n] = '\0';

        int j, flag, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == '0') {
                for (j = 1; j <= k; j++) {
                    if (inbounds(i+j, 0, n) && arr[i+j] == '1') {
                        flag = 1; break;
                    }   
                    if (inbounds(i-j, 0, n) && arr[i-j] == '1') {
                        flag = 0; break;
                    }
                }
                if (j > k) {
                    arr[i] = '1'; cnt++; i+=k;
                } else {
                    if (flag == 1) {
                        i = i + j + k;
                    } else {
                        i = i - j + k;
                    }
                }
            }
        }

        cout << cnt << '\n';
        // cout << arr << '\n';
    }
    return 0;
}