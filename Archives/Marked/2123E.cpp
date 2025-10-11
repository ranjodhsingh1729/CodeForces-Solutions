#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long)((a) - (b) * floor((long double)(a) / (b))))
#define FIXIO                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int, int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pre(r, l) for (ll i = (r); i >= ll((l)); i--)
#define fro(l, r) for (ll i = (l); i <= ll((r)); i++)

void solve() {
  ll n;
  cin >> n;
  vector<int> A(n);
  for (auto &i : A)
    cin >> i;
  sort(A.begin(), A.end());

  /*
      Ans[k] = Count of numbers whoose freq is less than k and after removing
              them one doesn't need to remove all instances of lower numbers;

      left_limit = freq[a];
      right_limit = countj(A[j] > A[a]) + countj(A[j] < A[a]) - a + freq[a];
      condition of mex creation: left lim <= k <= right lim;

      Simplify Right Limit
      right_limit = n - freq[i] - a + freq[a];
      right_limit = n - a;

      -- it was that simple --
      -- THINK MONKEY THINK --
  */

  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    freq[A[i]]++;
  }

  vector<int> ans(n + 1 + 1, 0);
  for (int i = 0; i <= n; i++) {
    ans[freq[i]]++;
    ans[n - i + 1]--;
    if (!freq[i])
        break;
  }

  int cur_ans = 0;
  for (int i = 0; i <= n; i++) {
    cur_ans += ans[i];
    cout << cur_ans << ' ';
  }
  cout << '\n';

}

int main() {
  FIXIO;

  ll t;
  t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}