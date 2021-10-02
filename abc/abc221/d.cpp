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
    vector<pair<ll, int>> date;
    rep (i, n)
    {
        int a, b;
        cin >> a >> b;
        date.push_back(make_pair(a, 1));
        date.push_back(make_pair(a + b, -1));
    }

    sort(date.begin(), date.end());
    vector<int> ans(n, 0);
    int cnt = 1;
    for (int i = 1; i < 2 * n; i++)
    {
        if (cnt - 1 >= 0)
            ans[cnt - 1] += date[i].first - date[i - 1].first;
        cnt += date[i].second;
    }

    for (const auto& x : ans)
        cout << x << ' ';
    cout << endl;
    return 0;
}