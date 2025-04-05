#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    map <char, int> freq, freq2;

    int t;
    cin >> t;

    int n;
    string x;
    while (t--) {
        freq.clear();
        freq2.clear();

        cin >> x;
        n = x.length();

        int count = 1;
        char curr = x[0];
        for (int i = 1; i < n; i++) {
            if (x[i] != curr) {
                freq[curr]++;
                if (freq2[curr]) {
                    freq2[curr] = min(count, freq2[curr]);
                } else {
                    freq2[curr] = count;
                }

                count = 1;
                curr = x[i];
            } else {
                count++;
            }
        }
        freq[curr]++;
        if (freq2[curr]) {
            freq2[curr] = min(count, freq2[curr]);
        } else {
            freq2[curr] = count;
        }

        int best = n+1;
        for (auto i = freq.begin(); i != freq.end(); i++) {
            best = min(best, i->second);
            // cout << i->first << ':' << i-> second << '\n';
        }

        int best2 = n+1;
        for (auto i = freq2.begin(); i != freq2.end(); i++) {
            if (freq[i->first] == best) {
                best2 = min(best2, i->second);
            }
        }

        
    }

    return 0;
}