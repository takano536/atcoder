#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

using mint = modint998244353;

mint dp[100100][10];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep (i, n)
        cin >> a[i];

    rep (i, 10)
        rep (j, 100100)
            dp[i][j] = 0;
    dp[0][a[0]] = 1;
    for (int i = 1; i < n; i++)
        rep (j, 10)
        {
            if (dp[i - 1][j] == 0)
                continue;
            int mul = (j * a[i]) % 10;
            int add = (j + a[i]) % 10;
            dp[i][mul] += dp[i - 1][j];
            dp[i][add] += dp[i - 1][j];
        }

    for (const auto& ans : dp[n - 1])
        cout << ans.val() << endl;
    return 0;
}