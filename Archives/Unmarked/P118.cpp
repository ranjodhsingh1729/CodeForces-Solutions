#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int less_than(int x, int n, int arr[]) {
    int l = 0, h = n, p;
    while (h - l) {
        p = (l+h)/2;
        if (x > arr[p]) {
            l = p+1;
        } else if (x < arr[p]) {
            h = p;
        } else {
            return p;
        }
    }
    return l;
}

int main() {
    map <int, int> freq;

    int t;
    cin >> t;

    int k, temp;
    int n, arr[MAXLEN * 2];
    while (t--) {
        k = 0;
        freq.clear();


        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (freq[arr[i]] == 1) arr[k++] = arr[i];
        }
        
        sort(arr, arr+k);

        temp = arr[0];
        for (int i = 0; i < k; i++) {
            arr[i] -= temp;
        }

        cout << less_than(n, k, arr) << '\n';
    }

    return 0;
}