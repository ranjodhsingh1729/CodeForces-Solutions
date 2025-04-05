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

void solve() {
    ll n;
    cin >> n;
    vector<pair<int,int>> gates(n);
    vector<pair<bool,bool>> types(n);
    char temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        types[i].first = (temp == 'x');
        cin >> gates[i].first;
        cin >> temp;
        types[i].second = (temp == 'x');
        cin >> gates[i].second;
    }

    int f;
    vector<pair<ll, ll>> mules;
    for (int i = 0; i < n; i++) {
        if (types[i].first && types[i].second) {
            if (gates[i].first == gates[i].second)
                continue;
            f = gates[i].first < gates[i].second;
        } else if (types[i].second) {
            f = 1;
        } else if (types[i].first) {
            f = 0;
        } else {
            continue;
        }
        mules.push_back({i, f});
    }
    
    ll cur_l = 1, cur_r = 1, inc, tmp;
    for (int i = 0; i < n-1; i++) {
        inc = 0;
        if (types[i].first) {
            inc += cur_l*(gates[i].first-1);
        } else {
            inc += gates[i].first;
        }
        if (types[i].second) {
            inc += cur_r*(gates[i].second-1);
        } else {
            inc += gates[i].second;
        }

        f = 0;
        if (types[i+1].first && types[i+1].second && gates[i+1].first == gates[i+1].second) {
            tmp = lower_bound(mules.begin(), mules.end(), i+2, 
                [](auto &x, auto &y){
                    return (y > x.first);
                }
            ) - mules.begin();
        } else {
            tmp = lower_bound(mules.begin(), mules.end(), i+1, 
                [](auto &x, auto &y){
                    return (y > x.first);
                }
            ) - mules.begin();
        }
        if (tmp < mules.size()) {
            f = mules[tmp].second;
        }
        
        if (f) {
            cur_r += inc;
        } else {
            cur_l += inc;
        }
    }

    inc = 0;
    if (types[n-1].first) {
        inc += cur_l*(gates[n-1].first-1);
    } else {
        inc += gates[n-1].first;
    }
    if (types[n-1].second) {
        inc += cur_r*(gates[n-1].second-1);
    } else {
        inc += gates[n-1].second;
    }

    if (types[n-1].first && types[n-1].second) {
        f = gates[n-1].first < gates[n-1].second;
    } else if (types[n-1].second) {
        f = 1;
    } else  {
        f = 0;
    }

    if (f) {
        cur_r += inc;
    } else {
        cur_l += inc;
    }

    cout << cur_l+cur_r << '\n';
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