#include <bits/stdc++.h>
 
#define MAXLEN 100000
 
using namespace std;
 
int main() {
   int sum, best, count;
   int n, arr[MAXLEN / 1000];
      cin >> n;
      
      count = 0;
      for (int i = 0; i < n; i++) {
         cin >> arr[i];
         if (arr[i]) { count++; arr[i] = -arr[i]; }
         else {arr[i] = arr[i] + 1;}
      }
 
      if (count == n) {
         cout << n - 1 << '\n'; return 0;
      }

      // kadane's algo
      sum = 0, best = 0;
      for (int i = 0; i < n; i++) {
         sum = max(arr[i], sum+arr[i]);
         best = max(best, sum);
      }
 
      cout << count + best << '\n';
}
