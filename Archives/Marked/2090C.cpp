#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pre(r, l) for (ll i = (r); i >= ll((l)); i--)
#define fro(l, r) for (ll i = (l); i <= ll((r)); i++)


void solve(vector<pair<int,int>> &cells) {
    ll n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int p = 0, k = 0;
    vector<bool> is_occupied(4*50000);
    for (int i = 0; i < n; i++) {
        if (!A[i]) {
            for (int j = k; j < 4*50000; j++) {
                if (!is_occupied[j] && cells[j].first%3==cells[j].second%3&&cells[j].first%3==1) {
                    k = j;
                    cout << cells[k].first << ' ' << cells[k].second << '\n';
                    is_occupied[k++] = true;
                    break;
                }
            }
        } else {
            while (is_occupied[p])
                p++;

            cout << cells[p].first << ' ' << cells[p].second << '\n';
            is_occupied[p++] = true;
        }
        k = max(k, p);
    }


}


int main() {
    FIXIO;

    ll t;
    t = 1;
    cin >> t;

    vector<pair<int,int>> cells(4*50000);
    vector<bool> is_occupied(4*50000, false);

    int dis = 2;
    int x, y, k = 0;
    while (k < 4*50000) {
        x = 1;
        y = dis-1;
        while (y > 0 && k < 4*50000) {
            if (x%3==0 || y%3==0) {
                x++, y--;  continue;
            }
            cells[k].first = x, cells[k].second = y;
            x++, y--, k++;
        }
        dis++;
    }

    sort(cells.begin(), cells.begin()+k,
        [](auto &a, auto &b){
            int x = a.first + a.second + (a.first%3==a.second%3&&a.first%3==2 ? 2 : 0);
            int y = b.first + b.second + (b.first%3==b.second%3&&b.first%3==2 ? 2 : 0);
            if (x == y) {
                if (a.first == b.first) {
                    return a.second < b.second;
                } else {
                    return a.first < b.first;
                }
            } else {
                return x < y;
            }
        }
    );

    // for (int i = 0; i < 1000; i++) {
    //     cout << cells[i].first << ' ' << cells[i].second << endl;
    // }

    while (t--) {
        solve(cells);
    }

    return 0;
}