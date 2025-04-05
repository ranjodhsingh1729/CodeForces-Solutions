#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int lessthanequal(int x, int l, int h, int arr[]) {
    int p;
    while (l < h) {
        p = (l+h)/2;
        if (arr[p] <= x) {
            l = p+1;
        } else if (arr[p] > x) {
            h = p;
        }
    }

    if (arr[l] <= x) {
        return l;
    } else {
        return l-1;
    }
}

int greaterthanequal(int x, int l, int h, int arr[]) {
    int p;
    while (l < h) {
        p = (l+h)/2;
        if (arr[p] < x) {
            l = p+1;
        } else if (arr[p] >= x) {
            h = p;
        }
    }
    
    if (arr[l] >= x) {
        return l;
    } else {
        return l+1;
    }
}

void solve() {
    ll n;
    cin >> n;
    vector <int> arr(n+1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    string x;
    cin >> x;

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == 'B') {
            swap(arr[i], arr[c++]);
        }
    }
    sort(arr.begin(), arr.begin()+c);
    sort(arr.begin()+c, arr.begin()+n);

    bool f = 1;
    for (int i = 0; f && i < c; i++) {
        if (arr[i] < i+1) {
            f = 0;
        }
    }

    for (int i = n-1; f && i >= c; i--) {
        if (arr[i] > i+1) {
            f = 0;
        }
    }

    if (f) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

}


int main() {
    FIXIO;

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}