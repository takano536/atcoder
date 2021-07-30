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

    vector<string> ans;
    for (int bit = 0; bit < (1 << n); bit++)
    {
        string s;
        rep (i, n)
            s += bit & (1 << i) ? '(' : ')';

        int left_cnt = 0, right_cnt = 0;
        int is_ok = true;
        for (char c : s)
        {
            if (c == '(')
                left_cnt++;
            else
                right_cnt++;
            if (right_cnt > left_cnt)
                is_ok = false;
        }
        if (right_cnt != left_cnt)
            is_ok = false;
        if (is_ok)
            ans.push_back(s);
    }
    sort(ans.begin(), ans.end());

    for (string s : ans)
        cout << s << endl;
    return 0;
}