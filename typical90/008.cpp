#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

using mint = modint1000000007;

const string TARGET = "atcoder";
const int LEN = TARGET.size();

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector dp(LEN + 1, vector<mint>(n + 1, 0));
    rep (i, n + 1)
        dp[0][i] = 1;
    for (int i = 1; i <= LEN; i++)
        for (int j = 1; j <= n; j++)
        {
            if (s[j - 1] == TARGET[i - 1])
                dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] += dp[i][j - 1];
        }

    cout << dp[LEN][n].val() << endl;
    return 0;
}