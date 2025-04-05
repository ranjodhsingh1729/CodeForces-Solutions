#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    int a1, a2, b1, b2;
    int k1, k2, k3, k4;
    
    while (t--) {
        cin >> a1 >> a2 >> b1 >> b2;
        k1 = a1 > b1 ? 1 : (a1 < b1 ? -1 : 0);
        k2 = a1 > b2 ? 1 : (a1 < b2 ? -1 : 0);
        k3 = a2 > b1 ? 1 : (a2 < b1 ? -1 : 0);
        k4 = a2 > b2 ? 1 : (a2 < b2 ? -1 : 0);
        
        cout << 2*(((k1 + k4) > 0 ? 1 : 0) + ((k2 + k3) > 0 ? 1 : 0)) << '\n';
        
    }

    

    return 0;
}