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
    vector<int> a(n);
    rep (i, n)
        cin >> a[i];

    map<int, int> nums;
    rep (i, n)
        nums[(a[i] + 200) % 200]++;
    ll ans = 0;
    rep (i, n)
    {
        int find_num = (a[i] + 200) % 200;
        nums[find_num]--;
        auto itr = nums.find(find_num);
        if (itr == nums.end())
            continue;
        ans += itr->second;
    }

    cout << ans << endl;
    return 0;
}