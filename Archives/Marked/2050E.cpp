#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 1;
    cin >> t;
    int n, m;
    string a, b, c;
    while (t--) {
        cin >> a >> b >> c;
        n = a.size(), m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i-1][0] + (a[i-1] != c[i-1]);
        for (int i = 1; i <= m; i++)
            dp[0][i] = dp[0][i-1] + (b[i-1] != c[i-1]);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                dp[i][j] = min(
                    dp[i][j-1]+(c[i+j-1] != b[j-1]), 
                    dp[i-1][j]+(c[i+j-1] != a[i-1])
                );
        }
        cout << dp[n][m] << '\n';
    }
    return 0;
}