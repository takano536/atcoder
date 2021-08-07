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
    vector<int> a(n);
    rep (i, n)
        cin >> a[i];
    sort(a.begin(), a.end());

    int q;
    cin >> q;
    rep (i, q)
    {
        int b;
        cin >> b;
        auto upper_it = upper_bound(a.begin(), a.end(), b);
        if (upper_it == a.end())
            cout << abs(*(upper_it - 1) - b) << endl;
        else if (upper_it == a.begin())
            cout << abs(*upper_it - b) << endl;
        else
            cout << min(abs(*upper_it - b), abs(*(upper_it - 1) - b)) << endl;
    }

    return 0;
}