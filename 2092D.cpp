#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MmpXLEN 100001
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
    string s;
    cin >> s;

    map <char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    if (mp.size() == 1) {
        cout << -1 << '\n';
        return;
    }

    char a = (mp['T'] <= mp['I']) ? ((mp['T'] <= mp['L']) ? 'T' : 'L') : ((mp['I'] <= mp['L']) ? 'I' : 'L');
    char c = (mp['T'] > mp['I']) ? ((mp['T'] > mp['L']) ? 'T' : 'L') : ((mp['I'] > mp['L']) ? 'I' : 'L');
    char b;
    for (auto &i: "TIL") {
        if (i != a && i != c) {
            b = i;
            break;
        }
    }
    assert(a != b && a != c);

    vector <int> ans;
    int count = mp[b] - mp[a];
    for (int i = 0; count > 0 && i < s.size()-1; i++) {
        if (s[i] != s[i+1] && s[i] != a && s[i+1] != a) {
            count--;
            ans.push_back(i+1);
            s.insert(s.begin()+i+1, a);
        }
    }

    int st_idx = -1;
    for (int i = 0; count > 0 && i < s.size()-1; i++) {
        if (s[i] != s[i+1] && s[i] != c && s[i+1] != c) {
            st_idx = i;
            break;
        }
    }
    assert(count == 0 || st_idx != -1);

    for (int i = 0; i < 2*count; i++) {
        int idx = st_idx+1+(s[st_idx]==a?i:0);
        ans.push_back(idx);
        s.insert(s.begin()+idx, (i%2?a:c));
    }

    st_idx = -1;
    char mis_1, mis_2;
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] != s[i+1] && (s[i] == c || s[i+1] == c)) {
            st_idx = i;
            break;
        }
    }
    assert(st_idx != -1);

    mp.clear();
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    assert(mp[a] == mp[b]);

    for (int i = 0; i < 2*(mp[c]-mp[a]); i++) {
        ans.push_back(st_idx+1+(s[st_idx]!=c?i:0));
    }
    assert(ans.size() <= 2*n);

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
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