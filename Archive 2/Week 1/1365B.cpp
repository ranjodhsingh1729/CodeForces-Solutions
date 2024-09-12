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
 
bool issorted(int n, int arr[]) {
    for (int i = 0; i < n-1; i++) {
        if ((arr[i] > arr[i+1])) {
            return false;
        }
    }
    return true;
}
 
bool isarrequal(int n, int arr[]) {
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[0])
            return false;
    }
    return true;
}
 
int main() {
    init_io();
 
    int t;
    cin >> t;
 
    int n, arr[MAXLEN], brr[MAXLEN];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0 ; i < n; i++)
            cin >> brr[i];
 
        if (isarrequal(n, brr)) {
            if (issorted(n, arr)) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        } else {
            cout << "Yes" << '\n';
        }
    }
    return 0;
}