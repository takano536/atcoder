#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

using mint = modint1000000007;

int main()
{
    int n;
    cin >> n;
    vector<ll> c(n);
    rep (i, n)
        cin >> c[i];

    sort(c.begin(), c.end());
    mint ans = 1;
    rep (i, n)
        ans *= (c[i] - i);

    cout << ans.val() << endl;
    return 0;
}