#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;


void rev_arr_seg(int l, int r, int arr[]) {
    int temp;
    for (int i = 0; i <= (r-l)/2; i++) {
        temp = arr[l+i];
        arr[l+i] = arr[r-i];
        arr[r-i] = temp;
    }
}

bool is_sorted(int n, int arr[]) {
    for (int i = 0; i < n-1; i++) {
        if (arr[i+1] < arr[i])  {
            return false;
        }
    }
    return true;
}


int main() {
    int n, arr[MAXLEN];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    if (is_sorted(n, arr)) {
        cout << "yes" << '\n';
        cout << 1 << ' ' << 1 << '\n';
        return 0;
    }


    int l, r;
    int count = 0, flag = 0;
    for (int i = 0; i < n-1; i++) {
        if (count > 2) {
            cout << "no" << '\n';
            return 0;
        }

        if (flag ? arr[i] < arr[i + 1] : arr[i] > arr[i+1]) {
            if (!flag) {
                l = i;
                flag = 1;
            } else {
                r = i;
                flag = 0;
            }
            count++;
        }

        if (flag && i == n-2) {
            r = i+1;
        }
    }

    rev_arr_seg(l, r, arr);

    if (is_sorted(n, arr)) {
        cout << "yes" << '\n';
        cout << l+1 << ' ' << r+1 << '\n';
    } else {
        cout << "no" << '\n';
    }

    return 0;
}