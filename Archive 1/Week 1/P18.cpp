#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

void f0()
{
    cout << "NO" << '\n';
}

void f1(int n, int k)
{
    cout << "YES" << '\n';
    cout << n - 1 * (k - 1) << ' ';
    for (int i = 0; i < k - 1; i++)
        cout << 1 << ' ';
    cout << '\n';
}

void f2(int n, int k)
{
    cout << "YES" << '\n';
    cout << n - 2 * (k - 1) << ' ';
    for (int i = 0; i < k - 1; i++)
        cout << 2 << ' ';
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;

    int n, k;
    cout << fixed;
    while (t--)
    {
        cin >> n >> k;

        if (k > n)
        {
            cout << "NO" << '\n';
        }
        else
        {
            if (n % 2 && k % 2)
            {
                f1(n, k);
            }
            if (n % 2 && !(k % 2))
            {
                f0();
            }
            if (!(n % 2) && k % 2)
            {
                if (k > n / 2)
                {
                    f0();
                }
                else
                {
                    f2(n, k);
                }
            }
            if (!(n % 2) && !(k % 2))
            {
                if (k > n / 2)
                {
                    f1(n, k);
                }
                else
                {
                    f2(n, k);
                }
            }
        }
    }
}