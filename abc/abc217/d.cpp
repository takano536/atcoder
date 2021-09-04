#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int l, q;
    cin >> l >> q;
    vector<int> div;
    div.push_back(0);
    div.push_back(l);
    rep (i, q)
    {
        int c, x;
        cin >> c >> x;
        auto iter = lower_bound(div.begin(), div.end(), x);
        if (c == 1)
            div.insert(iter, x);
        else
            cout << *iter - *(iter - 1) << endl;
    }

    return 0;
}