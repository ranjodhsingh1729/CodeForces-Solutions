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
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> AB(n);

  for (int i = 0; i < n; i++) {
    cin >> AB[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> AB[i].second;
  }

  int a, b;
  ll ans = 0;
  for (auto &i : AB) {
    a = i.first, b = i.second;

    i.first = min(a, b);
    i.second = max(a, b);

    ans += i.second - i.first;
  }
  sort(AB.begin(), AB.end());

  /*
    ai, aj, bi, bj

    assuming: ai <= bi, aj <= bj && ai <= aj
          if (bi < aj)
              case 2, 3 wins
          else
              case 1 wins
    3 cases:
          |bi - ai| + |bj - aj|
          |aj - ai| + |bj - bi|
          |bj - ai| + |aj - bi|

    2nd and 3rd are equivalent and 1st is 2(aj - bi) less than the others
    if aj > bi then there is room for improovement other wise there is not.

    First priority find aj <= bi so we can move on with the current ans
    Secondly if first is not possible find the minimal aj - bi you can.
  */

  int minInc = INT_MAX;
  for (int i = 0; i < n - 1; i++) {
    int idx = lower_bound(AB.begin() + i + 1, AB.end(), AB[i].second,
        [](auto &a, auto &b) { return a.first < b; }) -  AB.begin();

    if (idx < n) {
      minInc = min(minInc, 2 * (AB[idx].first - AB[i].second));
    } else {
      minInc = 0;
      break;
    }
  }

  cout << ans + (minInc == INT_MAX ? 0 : minInc) << '\n';
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