#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string s1 = s.substr(0, n), s2 = s.substr(n);

    int q;
    cin >> q;
    bool rev = false;
    rep (i, q)
    {
        int t, a, b;
        cin >> t >> a >> b;
        a--, b--;

        if (t == 1)
        {
            if (b < n && !rev)
                swap(s1[a], s1[b]);
            else if (b < n && rev)
                swap(s2[a], s2[b]);
            else if (n <= a && !rev)
                swap(s2[a - n], s2[b - n]);
            else if (n <= a && rev)
                swap(s1[a - n], s1[b - n]);
            else if (!rev)
                swap(s1[a], s2[b - n]);
            else
                swap(s2[a], s1[b - n]);
        }
        else
            rev = !rev;
    }

    cout << (rev ? s2 + s1 : s1 + s2) << endl;
    return 0;
}