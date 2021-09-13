#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

vector<string> rotate_90(const vector<string>& shape)
{
    vector<string> ret(shape[0].size());
    for (int i = 0; i < shape[0].size(); i++)
        for (int j = shape.size() - 1; j >= 0; j--)
            ret[i].push_back(shape[j][i]);
    return ret;
}

vector<string> erase_dot(vector<string> shape)
{
    auto iter = shape.begin();
    while (iter != shape.end())
    {
        if (iter->find_first_not_of(".") == string::npos)
            iter = shape.erase(iter);
        else
            break;
    }
    iter = shape.end() - 1;
    while (iter != shape.begin())
    {
        if (iter->find_first_not_of(".") == string::npos)
            iter = shape.erase(iter), iter--;
        else
            break;
    }

    int loop_cnt = shape[0].size();
    int index = 0;
    rep (i, loop_cnt)
    {
        bool should_erase = true;
        rep (j, shape.size())
            should_erase = (should_erase && shape[j][index] == '.' ? true : false);
        if (!should_erase)
            break;
        rep (j, shape.size())
            shape[j].erase(index, 1);
    }
    loop_cnt = shape[0].size();
    index = shape[0].size() - 1;
    rep (i, loop_cnt)
    {
        bool should_erase = true;
        rep (j, shape.size())
            should_erase = (should_erase && shape[j][index] == '.' ? true : false);
        if (!should_erase)
            break;
        rep (j, shape.size())
            shape[j].erase(index, 1);
        index--;
    }

    return shape;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    for (auto& str : s)
        cin >> str;
    for (auto& str : t)
        cin >> str;

    s = erase_dot(s);
    t = erase_dot(t);
    bool ok = false;
    rep (i, 4)
    {
        s = rotate_90(s);
        if (s == t)
            ok = true;
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}