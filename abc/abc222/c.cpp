#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int judge(char a, char b)
{
    if (a == b)
        return 0;
    if (a == 'G' and b == 'P')
        return -1;
    if (a == 'C' and b == 'G')
        return -1;
    if (a == 'P' and b == 'C')
        return -1;
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(2 * n);
    rep (i, 2 * n)
        cin >> a[i];

    vector<pair<int, int>> ans(2 * n);
    rep (i, 2 * n)
        ans[i] = {0, i};
    vector<pair<int, int>> pairs(n);
    rep (i, n)
        pairs[i] = {i * 2, i * 2 + 1};
    rep (i, m)
    {
        sort(ans.begin(), ans.end(), [](const pair<int, int>& p, const pair<int, int>& q) { return p.second < q.second; });
        for (const auto& p : pairs)
        {
            if (judge(a[p.first][i], a[p.second][i]) == 0)
                continue;
            judge(a[p.first][i], a[p.second][i]) == 1 ? ans[p.first].first-- : ans[p.second].first--;
        }

        sort(ans.begin(), ans.end());
        rep (j, n)
            pairs[j] = {ans[j * 2].second, ans[j * 2 + 1].second};
    }

    sort(ans.begin(), ans.end());
    rep (i, 2 * n)
        cout << ans[i].second + 1 << endl;
    return 0;
}