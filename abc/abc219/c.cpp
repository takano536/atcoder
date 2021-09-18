#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

unordered_map<char, int> mp;
bool compare(string& s1, string& s2)
{
    int cnt = min(s1.size(), s2.size());
    rep (i, cnt)
    {
        if (mp[s1[i]] < mp[s2[i]])
            return true;
        else if (mp[s1[i]] > mp[s2[i]])
            return false;
    }
    if (s1.size() < s2.size())
        return true;

    return false;
}

int main()
{
    string x;
    cin >> x;
    int n;
    cin >> n;
    vector<string> s(n);
    rep (i, n)
        cin >> s[i];

    rep (i, 26)
        mp[x[i]] = i;
    sort(s.begin(), s.end(), compare);

    for (auto ans : s)
        cout << ans << endl;
    return 0;
}