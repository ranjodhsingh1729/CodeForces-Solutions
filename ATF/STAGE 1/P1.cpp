#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector <long long> arr;
    long long temp, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
        arr.push_back(temp);
    }
    
    if (n % 2) {
        long long mn = arr[0];
        for (int i = 1; i < n; i++) {
            mn = min(mn, arr[i]);
        }
        cout << sum-mn << '\n';
    } else {
        cout << sum << '\n';
    }

    return 0;
}