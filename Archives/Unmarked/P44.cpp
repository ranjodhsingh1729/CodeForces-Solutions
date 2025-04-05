    #include <bits/stdc++.h>

    #define MAXLEN 100000

    using namespace std;

    int monel(int n, int arr[]) {
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
            if (arr[i] < min) min = arr[i];
        return min;
    }

    int main() {
        map <int, int> freq;

        int x;
        int n, k, arr[MAXLEN * 2];

        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        if (k == 0) {
            cout << (monel(n, arr) == 1 ? -1 : 1) << '\n'; return 0;
        }

        int fsum = 0;

        auto i = freq.begin();
        for (i = freq.begin(); i != freq.end(); i++) {
            fsum += i->second;
            if (k == fsum) {
                cout << i->first << '\n'; 
                break;
            }
        }

        if (i == freq.end()) {
            cout << -1 << '\n';
        }


        return 0;
    }