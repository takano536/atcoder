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

    dsu d(2 * 1e5);
    rep (i, floor(n * 0.5))
        if (--a[i] != --a[n - 1 - i])
            d.merge(a[i], a[n - 1 - i]);

    cout << 2 * 1e5 - d.groups().size() << endl;
    return 0;
}