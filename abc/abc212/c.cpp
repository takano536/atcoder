#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<pair<int, char>> all;
    rep (i, n)
        cin >> a[i], all.push_back(make_pair(a[i], 'a'));
    rep (i, m)
        cin >> b[i], all.push_back(make_pair(b[i], 'b'));

    sort(all.begin(), all.end());
    int i = 0, j = 0;
    vector<int> index;
    rep (i, n + m - 1)
        if (all[i].second != all[i + 1].second)
            index.push_back(i);
    int ans = 1e9;
    for (int i : index)
        ans = min(abs(all[i].first - all[i + 1].first), ans); 

    cout << ans << endl;
    return 0;
}