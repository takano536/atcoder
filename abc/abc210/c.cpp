#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep (i, n)
        cin >> a[i];

    int ans = 0;
    unordered_map<int, int> mp;
    rep (i, k)
        mp[a[i]]++;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
        if (itr->second > 0)
            ans++;
    if (ans == k)
    {
        cout << ans << endl;
        return 0;
    }

    int cnt = ans;
    for (int i = k; i < n; i++)
    {
        mp[a[i - k]]--;
        if (mp[a[i - k]] == 0)
            cnt--;
        mp[a[i]]++;
        if (mp[a[i]] == 1)
            cnt++;
        ans = max(cnt, ans);
        if (ans == k)
            break;
    }

    cout << ans << endl;
    return 0;
}