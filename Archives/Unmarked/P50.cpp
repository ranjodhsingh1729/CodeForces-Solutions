#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, q, max, count;
    string str;
    char c;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        cin >> str;
        max = 1;
        count = 1;
        for (int i = 1; i < n; i++)
        {
            if (str[i] == str[i - 1])
            {
                count++;
                if (max < count)
                    max = count;
            }
            else
                count = 1;
        }
        cout << max << " ";
        for (int i = 0; i < q; i++)
        {
            cin >> c;
            str.push_back(c);
            if (str[n + i] == str[n + i - 1])
            {
                count++;
                if (max < count)
                    max = count;
            }
            else
                count = 1;
            cout << max << " ";
        }
        cout << "\n";
    }
}