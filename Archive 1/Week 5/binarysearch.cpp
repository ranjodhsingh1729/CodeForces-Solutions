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

int binarysearch(int x, int n, int arr[]) {
    int p, l = 0, h = n;
    while (l != h) {
        p = (l + h) / 2;
        if (x < arr[p]) {
            h = p;
        } else if (x > arr[p]) {
            l = p + 1;
        } else {
            return p;
        }
    }
    return -1;
}

int nlessthan(int x, int n, int arr[]) {
    int p, l = 0, h = n;
    while (l != h) {
        p = (l + h) / 2;
        if (x < arr[p]) {
            h = p;
        } else if (x > arr[p]) {
            l = p + 1;
        } else {
            if (p == 0) {
                return p;
            } else {
                if (x == arr[p-1]) {
                    h = p;
                } else {
                    return p;
                }
            }
        }
    }

    return l; // l == h
}

int ngreaterthanequalto(int x, int n, int arr[]) {
    int p, l = 0, h = n;
    while (l != h) {
        p = (l + h) / 2;
        if (x < arr[p]) {
            h = p;
        } else if (x > arr[p]) {
            l = p + 1;
        } else {
            if (p == 0) {
                return n-p;
            } else {
                if (x == arr[p-1]) {
                    h = p;
                } else {
                    return n-p;
                }
            }
        }
    }
    return n-l; // l == h
}

int nlessthanequalto(int x, int n, int arr[]) {
    int p, l = 0, h = n;
    while (l != h) {
        p = (l + h) / 2;
        if (x < arr[p]) {
            h = p;
        } else if (x > arr[p]) {
            l = p + 1;
        } else {
            if (p == n-1) {
                return p+1;
            } else {
                if (x == arr[p+1]) {
                    l = p+1;
                } else {
                    return p+1;
                }
            }
        }
    }

    return h; // l == h
}

int ngreaterthan(int x, int n, int arr[]) {
    int p, l = 0, h = n;
    while (l != h) {
        p = (l + h) / 2;
        if (x < arr[p]) {
            h = p;
        } else if (x > arr[p]) {
            l = p + 1;
        } else {
            if (p == n-1) {
                return n-(p+1);
            } else {
                if (x == arr[p+1]) {
                    l = p+1;
                } else {
                    return n-(p+1);
                }
            }
        }
    }

    return n-h; // l == h
}


int main() {
    init_io();

    int t;
    cin >> t;

    int n, x, arr[MAXLEN * 3];
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        sort(arr, arr+n);

        cout << ngreaterthanequalto(x, n, arr) << '\n';
        
    }

    return 0;
}