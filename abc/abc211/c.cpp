#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

using mint = modint1000000007;

const string target = "chokudai";
mint dp[8][100100];

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        dp[0][i] = dp[0][i - 1] + (s[i - 1] == target[0]);
    rep (i, target.size())
        dp[i][0] = 0;
    for (int i = 1; i < target.size(); i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (s[j - 1] == target[i] ? dp[i - 1][j - 1] + dp[i][j - 1] : dp[i][j - 1]);

    cout << dp[target.size() - 1][n].val() << endl;
    return 0;
}