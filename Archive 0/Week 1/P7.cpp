#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int pairs(int m, int n, int males[], int females[]) {
    int count = 0;
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (females[j] > males[i] + 1) {
            i++;
        } else if (females[j] < males[i] - 1) {
            j++;
        } else {
            i++, j++, count++;
        }
    }

    return count;
}

int main() {
    int m, arr_m[MAXLEN / 1000];
    int f, arr_f[MAXLEN / 1000];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> arr_m[i];
    
    cin >> f;
    for (int i = 0; i < f; i++)
        cin >> arr_f[i];

    sort(arr_m, arr_m+m);
    sort(arr_f, arr_f+f);

    if (m <= f) {
        cout << pairs(m, f, arr_m, arr_f) << '\n';
    } else {
        cout << pairs(f, m, arr_f, arr_m) << '\n';
    }
}