#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> a(n), b(n);
    rep (i, n)
        cin >> a[i].first >> b[i].first, a[i].second = i, b[i].second = i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pair<int, int>> ans(n);
    int a_now = a[0].first, b_now = b[0].first;
    int a_cnt = 1, b_cnt = 1;
    rep (i, n)
    {
        if (a[i].first != a_now)
            a_cnt++, a_now = a[i].first;
        if (b[i].first != b_now)
            b_cnt++, b_now = b[i].first;
        ans[a[i].second].first = a_cnt;
        ans[b[i].second].second = b_cnt;
    }

    rep (i, n)
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}