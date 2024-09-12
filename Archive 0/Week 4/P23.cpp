#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    string x;
    int arr[4];
    while (t--) {
        cin >> x;

        int curr = 0, best = x.length()+1;
        arr[1] = arr[2] = arr[3] = 0;
        for (int i = 0; i < x.length(); i++) {
            arr[x[i] - '0'] = i+1;
            if ((arr[1] != 0) && (arr[2] != 0) && (arr[3] != 0)) {
                curr = max(arr[1], max(arr[2], arr[3])) - min(arr[1], min(arr[2], arr[3])) + 1;
                if (curr < best) {
                    best = curr;
                }
            }
        }

        cout << (best != x.length()+1 ? best : 0)  << '\n';
    }

    return 0;
}