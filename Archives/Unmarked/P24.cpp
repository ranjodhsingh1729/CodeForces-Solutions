#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int numofone(int p, int q, int n, int arr[]) {
    int count = 0;
    for (int i = 0; i < p; i++)
        if (arr[i] == 1) count++;
    for (int i = p; i <= q; i++)
        if (arr[i] == 0) count++;
    for (int i = q+1; i < n; i++)
        if (arr[i] == 1) count++;
    return count;
}

int main() {
    int count, max_count;
    int n, arr[MAXLEN / 1000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    max_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            count = numofone(i, j, n, arr);
            if (count >= max_count) {
                max_count = count;
            }
        }
    }

    cout << max_count << '\n';

}