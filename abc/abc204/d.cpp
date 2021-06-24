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
    vector<int> t(n + 1);
    rep (i, n)
        cin >> t[i + 1];

    int t_sum = accumulate(t.begin(), t.end(), 0);
    vector<vector<bool>> dp(n + 1, vector<bool>(t_sum + 1));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
        rep (j, t_sum + 1)
        {
            if (dp[i - 1][j])
                dp[i][j] = true;
            if (j - t[i] < 0)
                continue;
            if (dp[i - 1][j - t[i]])
                dp[i][j] = true;
        }

    vector<int> candidate;
    rep (i, t_sum + 1)
        if (dp[n][i])
            candidate.push_back(i);
    auto ans = lower_bound(candidate.begin(), candidate.end(), ceil(double(t_sum) / 2));
    cout << *ans << endl;
}