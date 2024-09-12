#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

void init_io() {
    #ifndef ONLINE_JUDGE
    freopen("streams/input.txt", "r", stdin);
    freopen("streams/output.txt", "w", stdout);
    #endif
}

int main() {
    unordered_map <int, int> frq;
    init_io();

    int t;
    cin >> t;

    int n, tmp, arr[30];
    while (t--) {
        frq.clear();

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            frq[tmp%10]++;
        }

        int l = 0;
        for (auto i = frq.begin(); i != frq.end(); i++) {
            // cout << i->first << " : " << i->second << '\n';
            i->second = i->second > 3 ? 3 : i -> second;
            for (int j = 0; j < i->second; j++) {
                arr[l++] = i->first;
            }
        }

        bool flag = 0;
        for (int i = 0; i < l; i++) {
            for (int j = i+1; j < l; j++) {
                for (int k = j+1; k < l; k++) {
                    if ((arr[i] + arr[j] + arr[k]) % 10 == 3) {
                        flag = 1; break;
                    }
                }
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';       
    }

    return 0;
}