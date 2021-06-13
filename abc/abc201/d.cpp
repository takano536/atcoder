#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> field(h, vector<int>(w));
    rep (i, h)
    {
        string s;
        cin >> s;
        rep (j, w)
            field[i][j] = (s[j] == '+' ? 1 : -1);
    }

    vector<vector<int>> dp(h, vector<int>(w, 0));
    for (int i = h - 1; i >= 0; i--)
        for (int j = w - 1; j >= 0; j--)
        {
            if (i == h - 1 && j == w - 1)
                continue;

            if ((i + j) % 2)
            {  // Aoki
                if (i == h - 1)
                    dp[i][j] = dp[i][j + 1] - field[i][j + 1];
                else if (j == w - 1)
                    dp[i][j] = dp[i + 1][j] - field[i + 1][j];
                else
                    dp[i][j] = min(dp[i][j + 1] - field[i][j + 1], dp[i + 1][j] - field[i + 1][j]);
            }
            else
            {  // Takahashi
                if (i == h - 1)
                    dp[i][j] = dp[i][j + 1] + field[i][j + 1];
                else if (j == w - 1)
                    dp[i][j] = dp[i + 1][j] + field[i + 1][j];
                else
                    dp[i][j] = max(dp[i][j + 1] + field[i][j + 1], dp[i + 1][j] + field[i + 1][j]);
            }
        }

    if (dp[0][0] == 0)
        cout << "Draw" << endl;
    else
        cout << (dp[0][0] > 0 ? "Takahashi" : "Aoki") << endl;
    return 0;
}