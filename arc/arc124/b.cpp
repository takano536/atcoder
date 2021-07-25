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
    vector<int> a(n), b(n);
    rep (i, n)
        cin >> a[i];
    rep (i, n)
        cin >> b[i];

    unordered_map<int, int> mp;
    rep (i, n)
    {
        set<int> st;
        rep (j, n)
        {
            int x = a[i] ^ b[j];
            if (st.find(x) != st.end())
                continue;
            mp[x]++;
            st.insert(x);
        }
    }

    vector<int> ans;
    for (auto p : mp)
        if (p.second == n)
            ans.push_back(p.first);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto m : ans)
        cout << m << endl;
    return 0;
}