#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    string s, t;
    cin >> s >> t;

    if (s == t)
    {
        cout << "Yes" << endl;
        return 0;
    }
    int len = s.size();
    rep (i, len - 1)
    {
        string u = s;
        swap(u[i], u[i + 1]);
        if (u == t)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}